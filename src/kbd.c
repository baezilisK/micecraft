#include <stdio.h>
#include "kbd.h"
#include "util.h"

void kbd_glutkeydown (unsigned char key, int x, int y) {
  (void) x; (void) y;
  kbd_state[kbd_map[key]] = 1;
  kbd_toggle[kbd_map[key]] ^= 1;
}

void kbd_glutkeyup (unsigned char key, int x, int y) {
  (void) x; (void) y;
  kbd_state[kbd_map[key]] = 0;
}

int kbd_setmap (char *path) {
  FILE *f = fopen (path, "r");
  int i, c;
  for (i = 0; i < arrlen (kbd_map); ++i)
    kbd_map[i] = f && (c = fgetc (f), c != EOF) ? c : i;
  return !f;
}
