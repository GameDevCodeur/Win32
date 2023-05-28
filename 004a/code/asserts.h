
#pragma once

#include <assert.h> // STATIC_ASSERT

// Defini correctement les assertions statiques.
#if defined(__clang__) || defined(__gcc__)
    #define STATIC_ASSERT _Static_assert
#else
    #define STATIC_ASSERT static_assert
#endif
