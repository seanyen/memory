#ifndef FOONATHAN_MEMORY_VISIBILITY_CONTROL_HPP_INCLUDED
#define FOONATHAN_MEMORY_VISIBILITY_CONTROL_HPP_INCLUDED

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define FOONATHAN_MEMORY_EXPORT __attribute__ ((dllexport))
    #define FOONATHAN_MEMORY_IMPORT __attribute__ ((dllimport))
  #else
    #define FOONATHAN_MEMORY_EXPORT __declspec(dllexport)
    #define FOONATHAN_MEMORY_IMPORT __declspec(dllimport)
  #endif
  #ifdef FOONATHAN_MEMORY_BUILDING_LIBRARY
    #define FOONATHAN_MEMORY_PUBLIC FOONATHAN_MEMORY_EXPORT
  #else
    #define FOONATHAN_MEMORY_PUBLIC FOONATHAN_MEMORY_IMPORT
  #endif
  #define FOONATHAN_MEMORY_PUBLIC_TYPE FOONATHAN_MEMORY_PUBLIC
  #define FOONATHAN_MEMORY_LOCAL
#else
  #define FOONATHAN_MEMORY_EXPORT __attribute__ ((visibility("default")))
  #define FOONATHAN_MEMORY_IMPORT
  #if __GNUC__ >= 4
    #define FOONATHAN_MEMORY_PUBLIC __attribute__ ((visibility("default")))
    #define FOONATHAN_MEMORY_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define FOONATHAN_MEMORY_PUBLIC
    #define FOONATHAN_MEMORY_LOCAL
  #endif
  #define FOONATHAN_MEMORY_PUBLIC_TYPE
#endif

#endif  // FOONATHAN_MEMORY_VISIBILITY_CONTROL_HPP_INCLUDED