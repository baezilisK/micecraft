#include <stdio.h>
#include <stdlib.h>
#include "GL/glut.h"

#include "cam.h"
#include "kbd.h"
#include "map.h"
#include "ugl.h"

#define H 480
#define W 640

static int skipmouse;  /*  mouse handler should ignore next event */

static void init (void) {
  glClearColor (0, 0, 0, 0);
  kbd_setmap ("assets/kbd/dvp");
  map_gen ();
}

static void main_exit (void) {
  exit (EXIT_SUCCESS);
}

static void display (void) {
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
  map_display ();
  glutSwapBuffers ();
}

static void reshape (int w, int h) {
  glViewport (0, 0, w, h);
  glMatrixMode (GL_PROJECTION); glLoadIdentity ();
    gluPerspective (60, 1.0*w/h, 0.01, 100);
    cam_sync ();
}

static void trackfps (void) {
  static int now, then, diff;
  now = glutGet (GLUT_ELAPSED_TIME);
  diff = now - then;
  printf ("Frame delay:\t%d ms (%.1f FPS)\n", diff, 1000.0/diff);
  then = glutGet (GLUT_ELAPSED_TIME);
}

static void tick (void) {
  float u = 0.06;
  if (kbd_state['w']) cam_mv (u, 0, 0);
  if (kbd_state['s']) cam_mv (-u, 0, 0);
  if (kbd_state['a']) cam_mv (0, -u, 0);
  if (kbd_state['d']) cam_mv (0, u, 0);
  if (kbd_state['c']) cam_mv (0, 0, -u);
  if (kbd_state[' ']) cam_mv (0, 0, u);
  if (kbd_toggle['q']) main_exit ();
}

static void timer (int s) {
  (void) s;
  tick ();
  trackfps ();
  cam_sync ();
  glutWarpPointer (
    glutGet (GLUT_WINDOW_WIDTH) / 2,
    glutGet (GLUT_WINDOW_HEIGHT) / 2
  );
  glutPostRedisplay ();
  glutTimerFunc (10, timer, 0);
}

static void mouse (int x, int y) {
  float s = 0.001, dx, dy;
  int
    cx = glutGet (GLUT_WINDOW_WIDTH) / 2,
    cy = glutGet (GLUT_WINDOW_HEIGHT) / 2;
  if (skipmouse)
    skipmouse = 0;
  else {
    dx = (cx - x) * s; dy = (cy - y) * s;
    cam_rotate (dx, dy);
  }
}

static void keyboard (unsigned char key, int x, int y) {
  if (kbd_map[key] == 'f') {
    skipmouse = 1;
    if (kbd_toggle['f']) glutReshapeWindow (W, H);
    else glutFullScreen ();
  }
  kbd_glutkeydown (key, x, y);
}

int main (int argc, char **argv) {
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (W, H);
  glutCreateWindow (argv[0]);
  init ();
  glutReshapeFunc (reshape);
  glutDisplayFunc (display);
  glutKeyboardFunc (keyboard);
  glutKeyboardUpFunc (kbd_glutkeyup);
  glutPassiveMotionFunc (mouse);
  glutTimerFunc (10, timer, 0);
  glutMainLoop ();
  exit (EXIT_FAILURE);
}
