/*
 * Utility for ratndom numbers
 */
#ifndef RNG_H
#define RNG_H

/*
 * Initialize random number generator. Must be called before any
 * other functions.
 */
void rng_init (void);

/*
 * Returns an integer in [0, n)
 */
int rng_i (int n);

/*
 * Returns a real in [0, 1]
 */
float rng_f (void);

/*
 * Delete random number generator. rng_init () must be called again
 * before any other functions.
 */
void rng_free (void);

#endif /* RNG_H */
