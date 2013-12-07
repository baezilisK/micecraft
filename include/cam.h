#ifndef CAM_H
#define CAM_H

/*
 * Location and direction of the camera.
 * The camera shall be at (cam_x, cam_y, cam_z); its direction
 * is by default towards (1, 0, 0), then rotated through cam_ti
 * in the xz plane, then rotated through cam_tj towards the
 * x-axis.
 *
 * Values for cam_tj outside of (-PI, PI) are valid, though can
 * look rather odd and probably isn't what you want.
 */
float
  cam_x, cam_y, cam_z, /* position */
  cam_ti, cam_tj;      /* rotation, ti real, -PI < tj < PI */

/*
 * Move the camera in the xy plane relative to its position.
 */
void cam_mv (float x, float y);

/*
 * Rotate the camera through a (xy plane) and b (xyz plane).
 * The angle b will be clamped such that -PI < cam_tj < PI.
 */
void cam_rotate (float a, float b);

/*
 * Synchronize GL_MODELVIEW matrix with camera state.
 */
void cam_sync (void);

#endif /* CAM_H */
