#include "GL/gl.h"

#define v(a,b,c) glVertex3f((a),(b),(c))

void ugl_rprism (float x, float y, float z, float r, float s, float t) {
  glBegin (GL_QUADS);
    v (x, y, z);
    v (x + r, y, z);
    v (x + r, y + s, z);
    v (x, y + s, z);

    v (x + r, y, z);
    v (x + r, y, z + t);
    v (x + r, y + s, z + t);
    v (x + r, y + s, z);

    v (x + r, y, z + t);
    v (x, y, z + t);
    v (x, y + s, z + t);
    v (x + r, y + s, z + t);

    v (x, y, z + t);
    v (x, y, z);
    v (x, y + s, z);
    v (x, y + s, z + t);

    v (x, y, z);
    v (x, y, z + t);
    v (x + r, y, z + t);
    v (x + r, y, z);

    v (x, y + s, z);
    v (x + r, y + s, z);
    v (x + r, y + s, z + t);
    v (x, y + s, z + t);
  glEnd ();
}

void ugl_cube (float x, float y, float z, float s) {
  ugl_rprism (x, y, z, s, s, s);
}
