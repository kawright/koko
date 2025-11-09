/* statout.h - static output */

#ifndef STATOUT_H
#define STATOUT_H

#include "core.h"
#include "err.h"

/* ----- FILE PATHS ----- */

#ifndef HELP_FILE_PATH
    #define HELP_FILE_PATH              "/asset/help.txt"
#endif

#ifndef VER_FILE_PATH
    #define VER_FILE_PATH               "/asset/version.txt"
#endif

/* ----- TYPES ----- */

typedef struct STRUCT_STAT_OUT {
    Ch      *help;
    Ch      *ver;
} StatOut;

/* ----- FUNCTIONS ----- */

Void init_stat_out(StatOut *stat_out);
Void load_stat_out(StatOut *stat_out, Err *err);
Void clean_stat_out(StatOut *stat_out);

#endif
