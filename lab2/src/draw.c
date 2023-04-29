#include <string.h>

#include <GL/gl.h>

#include "draw.h"
#include "mainwindow.h"
#include "rect.h"
#include "button.h"
#include "color.h"
#include "menu.h"
#include "mainmenu.h"
#include "charset.h"
#include "font.h"


void draw(void)
{
    glOrtho(
        0, main_window.size.width,
        main_window.size.height, 0,
        -1.0, 1.0
    );

    drawMenu(&main_menu);
}

void drawRect(const Rect *rect, const Color *color)
{
    setColor(color);

    glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_INT, 0, rect->vertices);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawRectFrame(
    const Rect *rect,
    const Color *color,
    _line_width_t line_width
)
{
    setColor(color);

    glEnableClientState(GL_VERTEX_ARRAY);
        glLineWidth(line_width);
        glVertexPointer(2, GL_INT, 0, rect->vertices);
        glDrawArrays(GL_LINE_LOOP, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawTextLine(
    const unsigned char *text,
    const Point pos,
    const Font *font
)
{
    glPushMatrix();

    glTranslated(pos.x, pos.y, 0);

    double k = font->line_height /
               (double)font->charset->char_cell_size;
    glScaled(k, k, 0);

    for (int i = 0; i < strlen(text); ++i) {
        const unsigned char ch = text[i];

        drawCharacter(ch, (Point){0, 0}, font);
        glTranslated(
            font->charset->char_width_array[ch] + font->letter_spacing,
            0, 0
        );
    }

    glPopMatrix();
}

void drawCharacter(
    unsigned char character,
    Point pos,
    const Font *font
)
{
    glPushMatrix();

    const Charset *charset = font->charset;

    Size character_size = {
        charset->char_width_array[character],
        charset->char_cell_size
    };

    Rect rect = getRect(pos, character_size);
    Rect texture_rect = getRect(
        (Point){
            (character & 15) * charset->char_cell_size,
            (character >> 4) * charset->char_cell_size
        },
        character_size
    );

    drawTexturedRect(
        &rect,
        &charset->texture,
        &texture_rect,
        font->color
    );

    glPopMatrix();
}

void drawTexturedRect(
    const Rect *rect,
    const Texture *texture,
    const Rect *texture_rect,
    const Color *fill_color
)
{
    if (!texture->id) return;  /* Error: texture is not loaded. */

    Rect full_texture_rect;

    if (!texture_rect) {
        full_texture_rect = getRect((Point){0, 0}, texture->size);

        texture_rect = &full_texture_rect;
    }

    double texture_coords[8];
    for (int i = 0; i < 8; i += 2) {
        texture_coords[i] = texture_rect->vertices[i >> 1].x
                          / (double)texture->size.width;
    }

    for (int i = 1; i < 8; i += 2) {
        texture_coords[i] = texture_rect->vertices[i >> 1].y
                          / (double)texture->size.height;
    }


    glBindTexture(GL_TEXTURE_2D, texture->id);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glTexCoordPointer(2, GL_DOUBLE, 0, texture_coords);

    drawRect(rect, fill_color);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindTexture(GL_TEXTURE_2D, 0);
}


void drawButton(const Button *button)
{
    glPushMatrix();

    drawRect(&button->rect, &button->palette[button->state]);
    drawRectFrame(&button->rect, &dimgray, 2.0f);

    const Font font = {
        &default_charset,
        &slategray,
        4,
        rectHeight(&button->rect)
    };

    drawTextLine(
        button->text,
        rectPos(&button->rect),
        &font
    );

    glPopMatrix();
}

void drawMenu(const Menu *menu)
{
    glPushMatrix();

    for (int i = 0; i < menu->buttons_count; ++i) {
        drawButton(menu->buttons + i);
    }

    glPopMatrix();
}
