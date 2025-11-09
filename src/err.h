/* err.h - error handling */

#ifndef ERR_H
#define ERR_H

#include "type.h"

#include <stdarg.h>

/* ----- BUFFER SIZES ----- */

#define ERR_FILE_BUF_SZ         64
#define ERR_MSG_BUF_SZ          256

/* ----- ERROR CODES ----- */

#define ERR_OK                  0
#define ERR_RUN                 1
#define ERR_ARGV                2
#define ERR_MEM                 3
#define ERR_IO                  4
#define ERR_BOUNDS              5

/* ----- MACROS ----- */

#define THROW(err, code, msg, ...) throw(err, code, __LINE__, __FILE__, msg, __VA_ARGS__);

/* ----- TYPES ----- */

typedef struct STRUCT_ERR {
    U16         ln;
    U8          code;
    Ch          file[ERR_FILE_BUF_SZ];
    Ch          msg[ERR_MSG_BUF_SZ];
} Err;

/* ----- FUNCTIONS ----- */

Void init_err(Err *err);
Bool is_err(Err *err);
Void throw(Err *err, U8 code, U16 ln, Ch *file, Ch *msg, ...);
Void warn(Err *err);

#endif
