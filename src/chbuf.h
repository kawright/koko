/* chbuf.h - character buffer */

#ifndef CHBUF_H
#define CHBUF_H

#include "core.h"
#include "err.h"

/* ----- TYPES ----- */

typedef struct STRUCT_CH_BUF {
    U64     sz;
    U64     curs;
    Ch      *data; 
} ChBuf;

/* ----- FUNCTIONS ----- */

Void adv_ch_buf(ChBuf *ch_buf, Err *err);
Void clean_ch_buf(ChBuf *ch_buf);
Void init_ch_buf(ChBuf *ch_buf);
Void load_ch_buf(ChBuf *ch_buf, Ch *file, Err *err);
Ch peek_ch_buf(ChBuf *ch_buf, Err *err);
Ch read_ch_buf(ChBuf *ch_buf);
U16 scan_until(ChBuf *ch_buf, Ch stop, Err *err);
U16 scan_while(ChBuf *ch_buf, Ch *legal, Err *err);
Ch *tell_ch_buf(ChBuf *ch_buf);

#endif
