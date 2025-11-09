/* err.c - error handling */

#include "core.h"
#include "err.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>


Void init_err(Err *err) {
    err->code           = ERR_OK;
    err->ln             = 0;
    err->file[0]		= '\0';
    err->msg[0]			= '\0';
}

Bool is_err(Err *err) {
    return (err->code != ERR_OK);
}

Void throw(Err *err, U8 code, U16 ln, Ch *file, Ch *msg, ...) {
    err->ln     = ln;
    err->code   = code; 
    strncpy(err->file, file, ERR_FILE_BUF_SZ - 1);

    // Write the error message:
    va_list args;
    va_start(args, msg);
    vsnprintf(err->msg, ERR_MSG_BUF_SZ - 1, msg, args);
    va_end(args);
}

Void warn(Err *err) {
    fprintf(stderr, "[%s:%d] %s\n", err->file, err->ln, err->msg);
}

