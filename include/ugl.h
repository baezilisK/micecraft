/*
 * Definition of useful OpenGL utilities
 */
#ifndef UGL_H
#define UGL_H

/*
 * Draws a cube of side s with lower-left corner at (x, y, z)
 */
void ugl_cube (float x, float y, float z, float s);

/*
 * Draws a rectangular prism at (x, y, z) with dimension (r, s, t).
 */
void ugl_rprism (float x, float y, float z, float r, float s, float t);

#endif /* UGL_H */
