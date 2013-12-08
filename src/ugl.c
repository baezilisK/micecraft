#include "GL/gl.h"

#define v(a,b,c) glVertex3f((a),(b),(c))

void ugl_cube (float x, float y, float z, float s) {
  glBegin (GL_QUADS);
    v (x, y, z);
    v (x + s, y, z);
    v (x + s, y + s, z);
    v (x, y + s, z);

    v (x + s, y, z);
    v (x + s, y, z + s);
    v (x + s, y + s, z + s);
    v (x + s, y + s, z);

    v (x + s, y, z + s);
    v (x, y, z + s);
    v (x, y + s, z + s);
    v (x + s, y + s, z + s);

    v (x, y, z + s);
    v (x, y, z);
    v (x, y + s, z);
    v (x, y + s, z + s);

    v (x, y, z);
    v (x, y, z + s);
    v (x + s, y, z + s);
    v (x + s, y, z);

    v (x, y + s, z);
    v (x + s, y + s, z);
    v (x + s, y + s, z + s);
    v (x, y + s, z + s);
  glEnd ();
}
