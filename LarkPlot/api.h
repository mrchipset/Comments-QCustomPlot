#ifndef LARK_PLOT_API_H
#define LARK_PLOT_API_H

#if LARK_SHARE_LIB
#if LARK_SHARE_LIB_EXPORT
#define LARK_API __declspec( dllexport )
#else
#define LARK_API __declspec( dllimport )
#endif
#else
#define LARK_API
#endif

#endif