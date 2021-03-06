#include <stdio.h>
#include <math.h>
#include "GL/gl.h"
#include "GL/glu.h"
#include "cam.h"
#include "map.h"
#include "util.h"

#define EPSILON 0.01

static void getdx (float *dx) {
  dx[0] = cos (cam_ti) * cos (cam_tj);
  dx[1] = sin (cam_ti) * cos (cam_tj);
  dx[2] = sin (cam_tj);
}

int cam_mv (float x, float y, float z) {
  int ret = -1;
  float
    dx = x * cos (cam_ti) + y * cos (cam_ti - PI/2),
    dy = x * sin (cam_ti) + y * sin (cam_ti - PI/2),
    dz = z;
  int i = cam_x + dx, j = cam_y + dy, k = cam_z + dz;
  if (!map_get (i, j, k)) {
    cam_x += dx; cam_y += dy; cam_z += dz;
    ret = 0;
  }
  return ret;
}

void cam_rotate (float a, float b) {
  cam_ti += a; cam_tj += b;
  if (cam_ti < -PI) cam_ti += 2*PI;
  if (cam_ti > PI) cam_ti -= 2*PI;
  if (cam_tj < -PI/2) cam_tj = -PI/2 + EPSILON;
  if (cam_tj > PI/2) cam_tj = PI/2 - EPSILON;
}

void cam_sync (void) {
  float dx[3];
  getdx (dx);
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
  gluLookAt (
    cam_x, cam_y, cam_z,
    cam_x + dx[0], cam_y + dx[1], cam_z + dx[2],
    0, 0, 1
  );
}
