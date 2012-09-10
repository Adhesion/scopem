/*
 * scale.h
 *
 * Scaling helper functions for normalizing parameters.
 *
 * @author Andrew Ford
 */

#ifndef __SCALE_H
#define __SCALE_H

/*
 * Scale takes input of [0.0-1.0] and scales to [min-max], descale does the
 * reverse. Inverse scaling (ie min > max) is supported.
 * Originally written as helper functions for interfacing with VST.
 */
float linearScale( float in, float min, float max );
float linearDescale( float in, float min, float max );

/*
 * Similar to the above functions, but exponential (base 2 for now)
 */
float expoScale( float in, float min, float max );
float expoDescale( float in, float min, float max );

#endif
