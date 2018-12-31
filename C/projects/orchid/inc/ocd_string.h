#ifndef __OCD_STRING_H__
#define __OCD_STRING_H__

__OCD_BEGIN_DECLS

#include <types.h>

typedef struct {
	ocd_size_t	len;
	ocd_uint8	*data;
}ocd_str_t;

#define ocd_string(str)		{ sizeof(str) - 1, (ocd_uint8 *) str }
#define ocd_null_string(str)	{ 0, OCD_NULL}

__OCD_END_DECLS

#endif /* end of include guard: __OCD_STRING_H__ */
/* vim: set ts=8 sw=8 noexpandtab: */
