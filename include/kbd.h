#ifndef KBD_H
#define KBD_H

#include <limits.h>

/*
 * When initialized, this maps keys to their corresponding value.
 */
unsigned char kbd_map[UCHAR_MAX + 1];

/*
 * Stores a state for each key. The meaning of each state
 * (0, 1, etc) is left to the user.
 */
int kbd_state[UCHAR_MAX + 1];

/*
 * The value for any given key should be inverted each time that key is
 * pressed.
 */
int kbd_toggle[UCHAR_MAX + 1];

/*
 * A function that may be registered with glutKeyboardFunc
 * that maintains the kbd_state and kbd_toggled structures.
 */
void kbd_glutkeydown (unsigned char key, int x, int y);

/*
 * A function that may be registered with glutKeyboardUpFunc
 * that maintains the kbd_state and kbd_toggled structures.
 */
void kbd_glutkeyup (unsigned char key, int x, int y);


/*
 * Set the keyboard map from the data in the file referenced by path.
 * Used to support different keyboard layouts, so note that qwerty
 * should be the identity map.
 *
 * The referenced map should be such that the ith byte will be the new
 * value of kbd_map[i]. If the file is insufficently large the map
 * will be padded with the identity, ie kbd_map[i] = i.
 *
 * A return value of 0 indicates success, error otherwise.
 * On error, the map is set to the identity before returning.
 */
int kbd_setmap (char *path);

#endif /* KBD_H */
