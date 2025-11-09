/* statout.c - static output */

#include "core.h"
#include "statout.h"

#include <stdio.h>
#include <stdlib.h>

Void init_stat_out(StatOut *stat_out) {
    stat_out->help      = NIL;
    stat_out->ver       = NIL;
}

Void load_stat_out(StatOut *stat_out, Err *err) {
    U64     help_file_sz, ver_file_sz, bytes_read;
    FILE    *help_fp, *ver_fp;

    // HELP FILE LOADING
    help_fp = fopen("asset/help.txt", "r");
    if (help_fp == NIL) {
        THROW(err, ERR_IO, "Could not open file %s", "asset/help.txt")
        return; 
    }
    fseek(help_fp, 0L, SEEK_END);
    help_file_sz = ftell(help_fp);
    rewind(help_fp);
    stat_out->help = malloc(help_file_sz + 1);
    if (stat_out->help == NIL) {
        THROW(err, ERR_MEM, "Could not allocate %d bytes", help_file_sz + 1)
        fclose(help_fp);
        return;
    }
    if ((bytes_read = fread(stat_out->help, 1, help_file_sz, help_fp)) != help_file_sz) {
        THROW(err, ERR_IO, "Read %ld of %ld bytes from file %s", help_file_sz, bytes_read, HELP_FILE_PATH)
        free(stat_out->help);
        stat_out->help = NIL;
        fclose(help_fp);
        return;
    }
    fclose(help_fp);

    // VERSION FILE LOADING 
    ver_fp = fopen("asset/version.txt", "r");
    if (ver_fp == NIL) {
        THROW(err, ERR_IO, "Could not open file %s", "asset/version.txt")
        return; 
    }
    fseek(ver_fp, 0L, SEEK_END);
    ver_file_sz = ftell(ver_fp);
    rewind(ver_fp);
    stat_out->ver = malloc(ver_file_sz + 1);
    if (stat_out->ver == NIL) {
        THROW(err, ERR_MEM, "Could not allocate %d bytes", ver_file_sz + 1)
        fclose(ver_fp);
        return;
    }
    if ((bytes_read = fread(stat_out->ver, 1, ver_file_sz, ver_fp)) != ver_file_sz) {
        THROW(err, ERR_IO, "Read %ld of %ld bytes from file %s", ver_file_sz, bytes_read, VER_FILE_PATH)
        free(stat_out->ver);
        stat_out->ver = NIL;
        fclose(ver_fp);
        return;
    }
    fclose(ver_fp);     
}

Void clean_stat_out(StatOut *stat_out) {
    if (stat_out->help != NIL)
        free(stat_out->help);
    if (stat_out->ver != NIL)
        free(stat_out->ver);
    init_stat_out(stat_out);
}
