#include "GL/gl.h"

#include "chunk.h"
#include "ugl.h"

void chunk_display (chunk c, float x) {
  int i, j, k;
  glColor3ub (0xAA, 0xAA, 0xAA);
  for (i = 0; i < CHUNK_DX; ++i)
    for (j = 0; j < CHUNK_DY; ++j)
      for (k = 0; k < CHUNK_DZ; ++k)
        if (c[i][j][k])
          ugl_cube (i + x, j, k, 1);
}
