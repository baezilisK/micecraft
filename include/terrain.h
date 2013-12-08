/*
 * Module for generating heightmaps
 */
#ifndef TERRAIN_H
#define TERRAIN_H

/*
 * Initialize module so that height may be queried
 */
void terrain_init (void);

/*
 * Get the height of the generated terrain at (x, y).
 */
float terrain_h (float x, float y);

/*
 * Deallocate any memory use by the module.
 * The resut of calling terrain_h between terrain_del and terrain_init
 * is undefined.
 */
void terrain_del (void);

#endif /* TERRAIN_H */
