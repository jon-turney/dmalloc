/*
 * Defines for low level memory management routines
 *
 * Copyright 2000 by Gray Watson
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
 *
 * $Id: chunk.h,v 1.60 2000/05/15 22:30:05 gray Exp $
 */

#ifndef __CHUNK_H__
#define __CHUNK_H__

/* some argument defines */
#define CHUNK_PNT_EXACT		BIT_FLAG(0)	/* pointer must be on block */
#define CHUNK_PNT_LOOSE		BIT_FLAG(1)	/* looser checking */
#define CHUNK_PNT_NULL		BIT_FLAG(2)	/* watch for null char */

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/*
 * int _chunk_startup
 * 
 * DESCRIPTION:
 *
 * Startup the low level malloc routines.
 *
 * RETURNS:
 *
 * Success - 1
 *
 * Failure - 0
 *
 * ARGUMENTS:
 *
 * None.
 */
extern
int	_chunk_startup(void);

/*
 * Describe pnt from its FILE, LINE into BUF.  Returns BUF.
 */
extern
char	*_chunk_desc_pnt(char *buf, const int buf_size,
			const char *file, const unsigned int line);

/*
 * int _chunk_check
 *
 * DESCRIPTION:
 *
 * Run extensive tests on the entire heap.
 *
 * RETURNS:
 *
 * Success - 1 if the heap is okay
 *
 * Failure - 0 if a problem was detected
 *
 * ARGUMENTS:
 *
 * None.
 */
extern
int	_chunk_check(void);

/*
 * int _chunk_pnt_check
 *
 * DESCRIPTION:
 *
 * Run extensive tests on a pointer.
 *
 * RETURNS:
 *
 * Success - 1 if the pointer is okay
 *
 * Failure - 0 if not
 *
 * ARGUMENTS:
 *
 * func -> Function string which is checking the pointer.
 *
 * pnt -> Pointer we are checking.
 *
 * check -> Type of checking (see chunk.h).
 *
 * min_size -> Minimum size of bytes.
 */
extern
int	_chunk_pnt_check(const char *func, const void *pnt,
			 const int check, const int min_size);

/*
 * int _chunk_read_info
 *
 * DESCRIPTION:
 *
 * Return some information associated with a pointer.
 *
 * RETURNS:
 *
 * Success - 1 pointer is okay
 *
 * Failure - 0 problem with pointer
 *
 * ARGUMENTS:
 *
 * pnt -> Pointer we are checking.
 *
 * where <- Where the check is being made from.
 *
 * size_p <- Pointer to an unsigned int which, if not NULL, will be
 * set to the size of bytes from the pointer.
 *
 * alloc_size_p <- Pointer to an unsigned int which, if not NULL, will
 * be set to the total allocated size of bytes from the pointer.
 *
 * file_p <- Pointer to a character pointer which, if not NULL, will
 * be set to the file where the pointer was allocated.
 *
 * line_p <- Pointer to a character pointer which, if not NULL, will
 * be set to the line-number where the pointer was allocated.
 *
 * ret_attr_p <- Pointer to a void pointer, if not NULL, will be set
 * to the return-address where the pointer was allocated.
 *
 * seen_cp <- Pointer to an unsigned long which, if not NULL, will be
 * set to the number of times the pointer has been "seen".
 *
 * valloc_bp <- Pointer to an integer which, if not NULL, will be set
 * to 1 if the pointer was allocated with valloc() otherwise 0.
 */
extern
int	_chunk_read_info(const void *pnt, const char *where,
			 unsigned int *size_p,
			 unsigned int *alloc_size_p, char **file_p,
			 unsigned int *line_p, void **ret_attr_p,
			 unsigned long **seen_cp, int *valloc_bp);

/*
 * Log the heap structure plus information on the blocks if necessary
 */
extern
void	_chunk_log_heap_map(void);

/*
 * Get a SIZE chunk of memory for FILE at LINE.  FUNC_ID is the type
 * of function which generated this call.  If ALIGNMENT is greater
 * than 0 then try to align the returned block.
 */
extern
void	*_chunk_malloc(const char *file, const unsigned int line,
		       const unsigned long size, const int func_id,
		       const unsigned int alignment);

/*
 * Frees PNT from the heap.  REALLOC_B set if realloc is freeing a
 * pointer so doing count it as a free.  Returns FREE_ERROR or
 * FREE_NOERROR.
 *
 * NOTE: should be above _chunk_realloc which calls it.
 */
extern
int	_chunk_free(const char *file, const unsigned int line, void *pnt,
		    const int realloc_b);

/*
 * Reallocate a section of memory
 */
extern
void	*_chunk_realloc(const char *file, const unsigned int line,
			void *old_p, unsigned long new_size,
			const int func_id);

/*
 * Log present free and used lists
 */
extern
void	_chunk_list_count(void);

/*
 * Log statistics on the heap
 */
extern
void	_chunk_stats(void);

/*
 * Dump the pointer information that has changed since mark.  If
 * non_freed_b is 1 then log the new not-freed (i.e. used) pointers.
 * If free_b is 1 then log the new freed pointers.  If details_b is 1
 * then dump the individual pointer entries instead of just the
 * summary.
 */
extern
void	_chunk_log_changed(const unsigned long mark, const int not_freed_b,
			   const int freed_b, const int details_b);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __CHUNK_H__ */
