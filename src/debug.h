/* debug.h - debug tools */

#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>

#define ERR_DEBUG       200

#ifdef DEBUG_MODE_ENABLED
    #define ASSERT_TRUE(expr, msg, ...) \
        if (expr) { \
            fprintf(stderr, "[ASSERT %s:%d] ", __FILE__, __LINE__); \
            fprintf(stderr, msg, ##__VA_ARGS__); \
            exit(ERR_DEBUG); \
        }
#else
    #define ASSERT_TRUE(expr, msg, ...) do {} while(0); 
#endif

#ifndef DEBUG_MODE_ENABLED
    #define ASSERT_UNREACHABLE(msg, ...) \
        fprintf(stderr, "[UNREACHABLE %s:%d] ", __FILE__, __LINE__); \
        fprintf(stderr, msg, ##__VA_ARGS__); \
        exit(ERR_DEBUG);
#else
    #define ASSERT_UNREACHABLE(msg, ...) do {} while(0);
#endif

#ifndef DEBUG_MODE_ENABLED
    #define DEBUG_MSG(msg, ...) \
        printf("[DEBUG %s:%d] ", __FILE__, __LINE__); \
        printf(msg, ##__VA_ARGS__);
#else
    #define DEBUG_MSG(msg, ...) do {} while(0);
#endif

#endif
