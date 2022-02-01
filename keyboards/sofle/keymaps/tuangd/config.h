#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif
#define TAPPING_TERM 200

#ifdef DEBOUNCE
	#undef DEBOUNCE
#endif
#define DEBOUNCE 30

#ifdef TAPPING_TOGGLE
	#undef TAPPING_TOGGLE
#endif

#define TAPPING_TOGGLE 1

#define MOUSEKEY_INTERVAL 8
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 255
#define MOUSEKEY_MAX_SPEED 9
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_TIME_TO MAX 80
#define MOUSEKEY_WHEEL_MAX_SPEED 3
