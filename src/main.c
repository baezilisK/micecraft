#include <stdio.h>
#include <stdlib.h>
#include "GL/glut.h"

#include "cam.h"
#include "kbd.h"

#define H 480
#define W 640

static void init (void) {
  glClearColor (0, 0, 0, 0);
  kbd_setmap ("assets/kbd/dvp");
}

static void main_exit (void) {
  exit (EXIT_SUCCESS);
}

static void display (void) {
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glutWireCube (1);
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
  float u = 0.03;
  if (kbd_state['w']) cam_mv (u, 0);
  if (kbd_state['s']) cam_mv (-u, 0);
  if (kbd_state['a']) cam_mv (0, -u);
  if (kbd_state['d']) cam_mv (0, u);
  if (kbd_state['c']) cam_z -= u;
  if (kbd_state[' ']) cam_z += u;
  if (kbd_toggle['q']) main_exit ();
  if (kbd_toggle['f']) glutFullScreen (); else glutReshapeWindow (W, H);
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
  dx = (cx - x) * s; dy = (cy - y) * s;
  cam_rotate (dx, dy);
}

int main (int argc, char **argv) {
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (W, H);
  glutCreateWindow (argv[0]);
  init ();
  glutReshapeFunc (reshape);
  glutDisplayFunc (display);
  glutKeyboardFunc (kbd_glutkeydown);
  glutKeyboardUpFunc (kbd_glutkeyup);
  glutPassiveMotionFunc (mouse);
  glutTimerFunc (10, timer, 0);
  glutMainLoop ();
  exit (EXIT_FAILURE);
}
