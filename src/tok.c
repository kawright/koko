/* tok.c - language tokens */

#include "core.h"
#include "debug.h"
#include "err.h"
#include "tok.h"

#include <string.h>

Void init_tok(Tok *tok) {
    tok->type               = TokType_INIT;
    tok->sz                 = 0;
    tok->data.nil           = NIL; 
}

Void load_tok_ch(Tok *tok, Ch val) {
    tok->type               = TokType_CH;
    tok->sz                 = 0;
    tok->data.ch            = val;
}

Void load_tok_keyword(Tok *tok, Keyword val) {
    tok->type               = TokType_KEYWORD;
    tok->sz                 = 0;
    tok->data.keyword       = val;
}

Void load_tok_op(Tok *tok, Op val) {
    tok->type               = TokType_OP;
    tok->sz                 = 0;
    tok->data.op            = val;
}

Void load_tok_punct(Tok *tok, Punct val) {
    tok->type               = TokType_PUNCT;
    tok->sz                 = 0;
    tok->data.punct         = val;
}

Void load_tok_str(Tok *tok, TokType type, Ch *val, U16 sz) {
    switch (type) {
        case TokType_STR:
        tok->type           = TokType_STR;
        tok->data.str       = val;
        break;

        case TokType_NAME:
        tok->type           = TokType_NAME;
        tok->data.name      = val;
        break;

        case TokType_DOC:
        tok->type           = TokType_DOC;
        tok->data.doc       = val;
        break;

        default:
        ASSERT_UNREACHABLE("%s\n", "Illegal token type found")
        break;
    }
    tok->sz     = sz;
}
