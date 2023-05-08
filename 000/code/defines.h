
#pragma once

#include<assert.h> // STATIC_ASSERT
#include<inttypes.h>

// Types booleens.
typedef uint8_t b8;

#define TRUE 1
#define FALSE 0

// Defini correctement les assertions statiques.
#if defined(__clang__) || defined(__gcc__)
    #define STATIC_ASSERT _Static_assert
#else
    #define STATIC_ASSERT static_assert
#endif

// Ne pas detecter error -Winvalid
#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Winvalid-source-encoding"
#endif

// Verifier que tous les types sont de la bonne taille.
STATIC_ASSERT(sizeof(b8) == 1, "b8 attendu doit être de 1 octet.");

#if defined(__clang__)
    #pragma clang diagnostic pop
#endif


