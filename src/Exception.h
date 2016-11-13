/*
 * Exception.h
 *
 *  Created on: 12 de nov de 2016
 *      Author: Rogério
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <setjmp.h>

#include "Object.h"

extern Class	ExceptionClass();

extern jmp_buf* currentExceptionBuffer;
extern void *	ExceptionCatch	();
extern void 	ExceptionEndTry	();
extern void		ExceptionThrow	(void * e);

#define try do {							\
	jmp_buf lbuf; 							\
	jmp_buf *prev = currentExceptionBuffer; \
	currentExceptionBuffer = &lbuf; 		\
	switch( setjmp(lbuf) ) { case 0: while(1) {

#define catch(e) break; case 1: e = ExceptionCatch();

#define finally  break; } default:{

#define endtry							\
		break;}}						\
		currentExceptionBuffer = prev;	\
		ExceptionEndTry();				\
		}while(0)

#define throw(e) ExceptionThrow((void *)e)

#define throws(x)

/*Object Attributes*/
typedef struct {
	OBJ_EXTENDS(Object);
} Exception;

/*Object Methods*/
typedef struct {
	OBJ_EXTENDS_METH(Object);
	int (*getValue)(const void * obj);
} TYPE_METH(Exception);

/*Object Creator*/
extern Exception * newException(int value);




#endif /* EXCEPTION_H_ */
