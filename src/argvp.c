/* argvp.c - argument vector parsing */

#include "argvp.h"
#include "core.h"
#include "err.h"

#include <getopt.h>

#define GETOPT_STR      "hpv"

Void init_opts(Opts *opts) {
    opts->help          = FALSE;
    opts->ver           = FALSE;
    opts->parse_only    = FALSE;
    opts->file          = NIL; 
}

Void parse_argv(Opts *opts, I16 argc, Ch **argv, Err *err) {
    opterr              = 0;             // Disables error messages from 'getopt'
    I16 curr_opt        = 0;
    while ((curr_opt = getopt(argc, argv, GETOPT_STR)) != -1) {
        switch (curr_opt) {

            case 'h':
            opts->help = TRUE;
            break;

            case 'p':
            opts->parse_only = TRUE;
            break;

            case 'v':
            opts->ver = TRUE;
            break;

            case '?':
            default:
            THROW(err, ERR_ARGV, "Illegal option found: %c", (Ch) curr_opt)
            return;
            break;

        }
    }
    if (optind != (argc - 1)) {
        THROW(err, ERR_ARGV, "Expected exactly one positional argument; %d found", argc - optind)
        return;
    }
    opts->file = argv[argc - 1];
}
