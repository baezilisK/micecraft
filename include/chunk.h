#ifndef CHUNK_H
#define CHUNK_H

#define CHUNK_DX 8
#define CHUNK_DY 8
#define CHUNK_DZ 8

typedef int chunk[CHUNK_DX][CHUNK_DY][CHUNK_DZ];

/*
 * Render the given chunk.
 */
void chunk_display (chunk c);

#endif /* CHUNK_H */
