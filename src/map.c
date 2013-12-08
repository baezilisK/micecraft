#include "chunk.h"
#include "map.h"
#include "rng.h"
#include "ugl.h"

static chunk map;

void map_gen (void) {
  int i, j, k;
  for (i = 0; i < CHUNK_DX; ++i)
    for (j = 0; j < CHUNK_DY; ++j)
      for (k = 0; k < CHUNK_DZ; ++k)
        map[i][j][k] = rng_f () < 0.1;
}

void map_set (int i, int j, int k, int val) {
  map[i][j][k] = val;
}

int map_get (int i, int j, int k) {
  return map[i][j][k];
}

void map_display (void) {
  int i, j, k;
  for (i = 0; i < CHUNK_DX; ++i)
    for (j = 0; j < CHUNK_DY; ++j)
      for (k = 0; k < CHUNK_DZ; ++k)
        if (map[i][j][k])
          ugl_cube (i, j, k, 1);
}

void map_del (void) {
}
