/*
 * header file for compatibility functions.
 *
 * Copyright 1992 by Gray Watson and the Antaire Corporation
 *
 * This file is part of the malloc-debug package.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library (see COPYING-LIB); if not, write to the
 * Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * The author of the program may be contacted at gray.watson@antaire.com
 *
 * $Id: compat.h,v 1.10 1993/04/30 20:02:26 gray Exp $
 */

#ifndef __COMPAT_H__
#define __COMPAT_H__

#include "conf.h"				/* for HAVE... */
#include "malloc_loc.h"				/* for IMPORT ... */

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/*
 * copy LEN characters from FROM to TO
 */
#ifndef HAVE_MEMCPY
IMPORT	char	*memcpy(char * to, const char * from, MALLOC_SIZE len);
#endif

/*
 * compare LEN characters, return -1,0,1 if STR1 is <,==,> STR2
 */
#ifndef HAVE_MEMCMP
IMPORT	int	memcmp(const char * str1, const char * str2, MALLOC_SIZE len);
#endif

/*
 * set LEN characters in STR to character CH
 */
#ifndef HAVE_MEMSET
IMPORT	char	*memset(char * str, int ch, MALLOC_SIZE len);
#endif

/*
 * find CH in STR by searching backwards through the string
 */
#ifndef HAVE_INDEX
IMPORT	char	*index(const char * str, int ch);
#endif

/*
 * find CH in STR by searching backwards through the string
 */
#ifndef HAVE_RINDEX
IMPORT	char	*rindex(const char * str, int ch);
#endif

/*
 * concatenate STR2 onto the end of STR1
 */
#ifndef HAVE_STRCAT
IMPORT	char	*strcat(char * str1, const char * str2);
#endif

/*
 * returns -1,0,1 on whether STR1 is <,==,> STR2
 */
#ifndef HAVE_STRCMP
IMPORT	int	strcmp(const char * str1, const char * str2);
#endif

/*
 * return the length in characters of STR
 */
#ifndef HAVE_STRLEN
IMPORT	MALLOC_SIZE	strlen(const char * str);
#endif

/*
 * get the next token from STR (pass in NULL on the 2nd, 3rd, etc. calls),
 * tokens are a list of characters deliminated by a character from DELIM.
 * writes null into STR to end token.
 */
#ifndef HAVE_STRTOK
IMPORT	char	*strtok(char * str, char * delim);
#endif

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __COMPAT_H__ */