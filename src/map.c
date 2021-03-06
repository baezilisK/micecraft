#include <assert.h>
#include "GL/gl.h"

#include "chunk.h"
#include "map.h"
#include "rng.h"
#include "terrain.h"
#include "ugl.h"
#include "util.h"

static chunk chunks[36];

void map_gen (void) {
  int i, j, k, l;
  terrain_init ();
  for (l = 0; l < arrlen (chunks); ++l)
    for (i = 0; i < CHUNK_DX; ++i)
      for (j = 0; j < CHUNK_DY; ++j)
        for (k = 0; k < CHUNK_DZ; ++k)
          chunks[l][i][j][k] = rng_f () < 0.05;
  terrain_del ();
}

void map_set (int i, int j, int k, int val) {
  chunks[0][i][j][k] = val;
}

int map_get (int i, int j, int k) {
  if (i < 0 || j < 0 || k < 0) return 0;
  if (i > 32 || j > 8 || k > 8) return 0;
  return chunks[0][i][j][k];
}

float map_height (float x, float y, float z) {
  float a = 1000;
  int i = x, j = y, k = z;
  assert (x < a && y < a && z < a);
  for (; k >= 0 && !map_get (i, j, k); --k);
  return z - (k + 1);
}

void map_display (void) {
  int i;
  for (i = 0; i < arrlen (chunks); ++i) {
    glColor3f (0, 0, 1);
    ugl_rprism (CHUNK_DX*i, 0, 0, CHUNK_DX, CHUNK_DY, CHUNK_DZ);
    chunk_display (chunks[i], i * CHUNK_DX);
  }
}

void map_del (void) {
}
