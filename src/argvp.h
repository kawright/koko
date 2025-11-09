/* argvp.h - argument vector parsing */

#ifndef ARGVP_H
#define ARGVP_H

#include "core.h"
#include "err.h"

typedef struct STRUCT_OPTS {
    Bool        help;               // -h
    Bool        ver;                // -v
    Bool        parse_only;         // -p
    Ch          *file;              // 1st positional
} Opts;

Void init_opts(Opts *opts);
Void parse_argv(Opts *opts, I16 argc, Ch **argv, Err *err);

#endif
