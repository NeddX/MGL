#ifndef MGL_ASSERT_H
#define MGL_ASSERT_H

#ifdef __GNUC__
#define ASSERT(x) if (!(x)) __builtin_trap()
#elif _MSC_VER
#define ASSERT(x) if (!(x)) __debugbreak()
#elif __clang__
#define ASSERT(x) if (!(x)) __builtin_debugtrap()
#endif

#endif // MGL_ASSERT_H