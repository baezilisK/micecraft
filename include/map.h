/*
 * Interface for manipulating the map.
 */
#ifndef MAP_H
#define MAP_H

/*
 * Generate a new map.
 * When performing operations on the map, it is permitted to operate
 * on arbitrary points (i, j, k). However, the implementation is
 * permitted to slow down significantly when forced to deal with two
 * points a great distance from each other.
 */
void map_gen (void);

/*
 * Set the map value at (i, j, k).
 */
void map_set (int i, int j, int k, int val);

/*
 * Get the map value at (i, j, k).
 */
int map_get (int i, int j, int k);

/*
 * Get the clearance of (i, j, k) above the nearest block.
 * Eg, if a block is at the origin, then we have
 *   map_height (0.5, 0.5, 0.5) == 0. // (inside has no clearance);
 *   map_height (0.5, 0.5, 1.27) == 0.27 // (point is 0.27 above block)
 */
float map_height (float i, float j, float k);

/*
 * Display the map.
 */
void map_display (void);

/*
 * Delete the map
 */
void map_del (void);

#endif /* MAP_H */
