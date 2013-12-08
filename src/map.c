#include "chunk.h"
#include "map.h"
#include "rng.h"
#include "ugl.h"
#include "util.h"

static chunk chunks[1];

void map_gen (void) {
  int i, j, k, l;
  for (l = 0; l < arrlen (chunks); ++l)
    for (i = 0; i < CHUNK_DX; ++i)
      for (j = 0; j < CHUNK_DY; ++j)
        for (k = 0; k < CHUNK_DZ; ++k)
          chunks[l][i][j][k] = rng_f () < 0.1;
}

void map_set (int i, int j, int k, int val) {
  chunks[0][i][j][k] = val;
}

int map_get (int i, int j, int k) {
  return chunks[0][i][j][k];
}

void map_display (void) {
  int i;
  for (i = 0; i < arrlen (chunks); ++i) {
    ugl_cube (0, 0, 0, CHUNK_DX);
    chunk_display (chunks[i]);
  }
}

void map_del (void) {
}
