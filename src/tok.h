/* tok.h - language tokens */

#ifndef TOK_H
#define TOK_H

#include "core.h"

/* ----- TYPES ----- */

typedef enum ENUM_TOK_TYPE {
    TokType_KEYWORD,
    TokType_OP,
    TokType_STR,
    TokType_NAME,
    TokType_CH,
    TokType_PUNCT,
    TokType_DOC,
    TokType_END,
    TokType_INIT
} TokType;

typedef enum ENUM_KEYWORD {
    Keyword_ELIF,
    Keyword_ELSE,
    Keyword_FOR,
    Keyword_FN,
    Keyword_IF,
    Keyword_INCLUDE,
    Keyword_WHILE,
    Keyword_RETURN
} Keyword;

typedef enum ENUM_OP {
    Op_DBL_EQ,
    Op_EQ,
    Op_MINUS,
    Op_PLUS,
    Op_SLASH,
    Op_STAR
} Op;

typedef enum ENUM_PUNCT {
    Punct_ARROW,
    Punct_COLON,
    Punct_DBL_QUOTE,
    Punct_L_BRACE,
    Punct_L_PAREN,
    Punct_R_BRACE,
    Punct_R_PAREN,
    Punct_SINGLE_QUOTE
} Punct;

typedef union UNION_TOK_DATA {
    Ch          ch;
    Ch          *doc;
    Keyword     keyword;
    Ch          *name;
    Op          op;
    Punct       punct;
    Ch          *str;
    Void        *nil; 
} TokData;

typedef struct STRUCT_TOK {
    TokType     type;
    U16         sz;
    TokData     data;
} Tok;

/* ----- FUNCTIONS ----- */

Void init_tok(Tok *tok);
Void load_tok_ch(Tok *tok, Ch val);
Void load_tok_keyword(Tok *tok, Keyword val);
Void load_tok_op(Tok *tok, Op val);
Void load_tok_punct(Tok *tok, Punct val);
Void load_tok_str(Tok *tok, TokType type, Ch *val, U16 sz);

#endif
