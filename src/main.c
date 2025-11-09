/* main.c - entry point */

#include "argvp.h"
#include "chbuf.h"
#include "core.h"
#include "err.h"
#include "statout.h"

#include <stdio.h>

I16 main(I16 argc, Ch **argv) {
    
    // DECLARATION
    ChBuf       ch_buf;
    Err         err;
    StatOut     stat_out;
    Opts        opts;

    // INITIALIZATION
    init_ch_buf(&ch_buf);
    init_err(&err);
    init_stat_out(&stat_out);
    init_opts(&opts);

    // ARGV PARSING
    parse_argv(&opts, argc, argv, &err);
    if (is_err(&err)) {
        warn(&err);
        goto CLEANUP;
    }

    // STATIC OUTPUT HANDLING
    if (opts.help) {
        load_stat_out(&stat_out, &err);
        if (is_err(&err)) {
            warn(&err);
            goto CLEANUP;
        }
        printf("\n%s\n", stat_out.help);
        goto CLEANUP;
    }
    if (opts.ver) {
        load_stat_out(&stat_out, &err);
        if (is_err(&err)) {
            warn(&err);
            goto CLEANUP;
        }
        printf("\n%s\n", stat_out.ver);
        goto CLEANUP;
    }

    load_ch_buf(&ch_buf, opts.file, &err);
    if (is_err(&err)) {
        warn(&err);
        goto CLEANUP;
    }

    printf("Read %lld bytes from file %s\n", ch_buf.sz, opts.file);

    CLEANUP:
    clean_stat_out(&stat_out);    
    clean_ch_buf(&ch_buf);

    return err.code;
}
