/* chbuf.c - character buffer */

#include "chbuf.h"
#include "core.h"
#include "err.h"

#include <stdio.h>
#include <stdlib.h>

Void adv_ch_buf(ChBuf *ch_buf, Err *err) {
    if (ch_buf->curs >= ch_buf->sz) {
        THROW(err, ERR_BOUNDS, "Out-of-bounds character buffer access attempted at byte offset %ld", ch_buf->curs + 1)
        return;
    }
    ch_buf->curs++;
}

Void clean_ch_buf(ChBuf *ch_buf) {
    if (ch_buf->data != NIL)
        free(ch_buf->data);
    init_ch_buf(ch_buf);
}

Void init_ch_buf(ChBuf *ch_buf) {
    ch_buf->data    = NIL;
    ch_buf->sz      = 0;
    ch_buf->curs    = 0;
}

Void load_ch_buf(ChBuf *ch_buf, Ch *file, Err *err) {
    FILE    *fp;
    U64     bytes_read;
    fp = fopen(file, "r");
    if (fp == NULL) {
        THROW(err, ERR_IO, "Could not open file %s", file)
        return;
    }
    fseek(fp, 0L, SEEK_END); 
    ch_buf->sz = ftell(fp);
    rewind(fp);
    ch_buf->data = malloc(ch_buf->sz);
    if (ch_buf->data == NIL) {
        THROW(err, ERR_MEM, "Could not allocate %ld bytes", ch_buf->sz)
        fclose(fp);
        clean_ch_buf(ch_buf);
        return;
    }
    if ((bytes_read = fread(ch_buf->data, 1, ch_buf->sz, fp)) != ch_buf->sz) {
        THROW(err, ERR_MEM, "Read %ld of %ld bytes from file %s", bytes_read, ch_buf->sz, file)
        fclose(fp);
        clean_ch_buf(ch_buf);
        return;
    }
}

Ch peek_ch_buf(ChBuf *ch_buf, Err *err) {
    if (ch_buf->curs >= ch_buf->sz) {
        THROW(err, ERR_BOUNDS, "Out-of-bounds character buffer access attempted at byte offset %ld", ch_buf->curs + 1)
        return '\0';
    }
    return ch_buf->data[ch_buf->curs + 1];
}

Ch read_ch_buf(ChBuf *ch_buf) {
    return ch_buf->data[ch_buf->curs];
}

