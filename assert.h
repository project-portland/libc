/* * * * * * * * * * * * * * *
 * Portland libc assert.h    *
 * Copyright 2018 Benji Dial *
 * Under GNU GPL v3.0        *
 * * * * * * * * * * * * * * */

#ifdef NDEBUG
#define assert(ignore)((void) 0)
#else
#include <p-clib.h>
#include <stdlib.h>
#define assert(expr) if (!(expr)) { print_bytes("The assertion " #expr " in " __func__ " on line " __LINE__ " of " __FILE__ " failed.\n"); abort(); }
#endif
