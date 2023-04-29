#ifndef UPDATE_H_INCLUDED_
#define UPDATE_H_INCLUDED_


#include "types.h"


extern const _time_t update_delay;


/**
 * Main update function which is called every @a update_delay
 * milliseconds and every time mark window to be redisplayed
 * in the next iteration of glut main loop.
 */
void update(int value);

/**
 * Calls @a update function for the first time
 * to run update loop.
 */
void runUpdateLoop(void);


#endif  /* UPDATE_H_INCLUDED_ */
