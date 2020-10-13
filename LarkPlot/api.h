#ifndef LARK_PLOT_API.h
#define LARK_PLOT_API.h

#if SHARE_LIB
#if SHARE_LIB_EXPORT
#define API __declspec( dllexport )
#else
#define API __declspec( dllimport )
#endif
#else
#define API
#endif

#endif