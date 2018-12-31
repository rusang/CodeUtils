#ifndef __OCD_CDEFS_H__
#define __OCD_CDEFS_H__

/* C++ needs to know that types and declarations are C, not C++.  */
#ifdef	__cplusplus
# define __OCD_BEGIN_DECLS	extern "C" {
# define __OCD_END_DECLS	}
#else
# define __OCD_BEGIN_DECLS
# define __OCD_END_DECLS
#endif

#endif /* end of include guard: __OCD_CDEFS_H__ */
/* vim: set ts=8 sw=8 noexpandtab: */
