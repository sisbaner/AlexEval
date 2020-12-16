

/*! \file lib_imexport.h
    \ingroup tools

    This file allows to export functions and classes from this directory in a dynamic/shared lib and to append the
    correct __declspec() declaration on windows. If you want to export one, make sure you have set
    \code
    #include "lib_imexport.h"

    class LIB_EXPORT exportedClassName {
       ...
    };

    LIB_EXPORT void exportedFunctionName();
    \endcode

    Then when compiling define the preprocessor symbol \c LIB_IN_DLL when exporting AND using the classes/functions.
    When compiling the classes for export, also define the preprocessor symbol \c LIB_EXPORT_LIBRARY .
 */



#  ifndef __WINDOWS__
#    if defined(WIN32) || defined(WIN64) || defined(_MSC_VER) || defined(_WIN32)
#      define __WINDOWS__
#    endif
#  endif

#ifdef __WINDOWS__
#  ifdef LIB_IN_DLL
#    if defined(LIB_EXPORT_LIBRARY)
#      define LIB_EXPORT __declspec(dllexport)
#    else
#      define LIB_EXPORT __declspec(dllimport)
#    endif
#  else
#    define LIB_EXPORT
#  endif
#else
#  define LIB_EXPORT
#endif






