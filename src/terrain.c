#include <math.h>
#include "terrain.h"

void terrain_init (void) {
}

float terrain_h (float x, float y) {
  (void) y;
  return 4 * sin (x / 3);
}

void terrain_del (void) {
}
