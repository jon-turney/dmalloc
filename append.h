/*
 * Header file for string appending functions.
 *
 * Copyright 2020 by Gray Watson
 *
 * This file is part of the dmalloc package.
 *
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies, and that the name of Gray Watson not be used in advertising
 * or publicity pertaining to distribution of the document or software
 * without specific, written prior permission.
 *
 * Gray Watson makes no representations about the suitability of the
 * software described herein for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * The author may be contacted via http://dmalloc.com/
 */

#ifndef __APPENDER_H__
#define __APPENDER_H__

#if HAVE_STDARG_H
# include <stdarg.h>				/* for ... */
#endif

#include "conf.h"

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/*
 * Append string argument to destination up to limit pointer.  Pointer
 * to the end of the characters added will be returned.  No \0
 * character will be added.
 */
extern
char	*append_string(char *dest, const char *limit, const char *value);

/*
 * Append long value argument to destination up to limit pointer.
 * Pointer to the end of the added characters will be returned.  No \0
 * character will be added.  Variant of itoa() written by Lukas
 * Chmela which is released under GPLv3.
 */
extern
char	*append_long(char *dest, char *limit, long value, int base);

/*
 * Append unsigned long value argument to destination up to limit
 * pointer.  Pointer to the end of the added characters will be
 * returned.  No \0 character will be added.  Variant of itoa()
 * written by Lukas Chmela. Released under GPLv3.
 */
extern
char	*append_ulong(char *dest, char *limit, unsigned long value, int base);

/*
 * Append pointer value argument to destination up to limit pointer.
 * Pointer to the end of the added characters will be returned.  No \0
 * character will be added.  Variant of itoa() written by Lukas
 * Chmela which is released under GPLv3.
 */
extern
char	*append_pointer(char *dest, char *limit, PNT_ARITH_TYPE value, int base);

/*
 * Append a varargs format to destination.  Pointer to the end of the
 * characters added will be returned.  No \0 character will be added.
 */
extern
char	*append_vformat(char *dest, char *limit, const char *format,
			va_list args);

/*
 * Append a varargs format to destination.  Pointer to the end of the
 * added characters will be returned.  No \0 character will be added.
 */
extern
char	*append_format(char *dest, char *limit, const char *format, ...);

/*
 * Append \0 character to destination.  If dest is => limit then \0
 * will be written one character before the limit.  Pointer past the
 * end of the \0 character will be returned.
 */
extern
char    *append_null(char *dest, char *limit);

/*
 * Local implementation of snprintf.  We are doing this trying to not
 * use the system version which often can allocate memory itself
 * causing the library to go recursive.
 */
extern
int	loc_vsnprintf(char *buf, const int size, const char *format,
		      va_list args);

/*
 * Local implementation of snprintf.  We are doing this trying to not
 * use the system version which often can allocate memory itself
 * causing the library to go recursive.
 */
extern
int	loc_snprintf(char *buf, const int size, const char *format, ...);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __APPENDER_H__ */
