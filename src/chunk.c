#include "GL/gl.h"

#include "chunk.h"
#include "ugl.h"

void chunk_display (chunk c, float x) {
  int i, j, k;
  glColor3ub (0xAA, 0xAA, 0xAA);
  for (i = 0; i < 8; ++i)
    for (j = 0; j < 8; ++j)
      for (k = 0; k < 8; ++k)
        if (c[i][j][k])
          ugl_cube (i + x, j, k, 1);
}
