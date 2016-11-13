/*
 * Exception.c
 *
 *  Created on: 12 de nov de 2016
 *      Author: Rogério
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "Exception-private.h"



jmp_buf* currentExceptionBuffer = NULL;


static Exception * 	ThrowException 			= NULL;

void *  ExceptionCatch (){
	return ThrowException;
}

void ExceptionEndTry(){
	if (ThrowException) {
		Destroy(ThrowException);
		ThrowException = NULL;
	}
}

void ExceptionThrow (void * e){

	ThrowException = e;
	longjmp(*currentExceptionBuffer, 1);
}



/* Declare Private Object*/
OBJ_DECLARE(Exception);

/*
 *  Declarations
 **/

void 			ExceptionClass_ctor		(void * class, void * meth);
void 			Exception_ctor			(const void * obj, va_list * app);
void 			Exception_destroy		(const void * obj);
int 			Exception_getValue		(const void * obj);

/*
 *  Implementations
 **/


/* Class Definition function
 *
 *   The function Name MUST be [Object name]Class
 *   MUST call OBJ_START_CLASS macro
 *
 * */
Class ExceptionClass() {
	OBJ_START_CLASS(Exception);
}


/* Class Constructor:
 *
 *   The function name MUST be [Object name]Class_ctor
 *   This function is called on the first call of [Object name]Class()
 *   Should call the Class Constructor of SUPER Class and
 *     fill up the object with his own parameters
 *
 * */
void ExceptionClass_ctor(void * class, void * meth) {

/* Call Class Constructor of the SUPER Class */
	OBJECT_CLASS(ObjectClass())->class_ctor(class, meth);

/* Fill up Object Parameters*/

	/* Public Methods*/
	CAST_METH(Object, meth)->destroy		= Exception_destroy;
	CAST_METH(Exception, meth)->getValue	= Exception_getValue;

	/*Private Methods*/
	CAST_CLASS(Object, class)->super 		= ObjectClass();
	CAST_CLASS(Object, class)->class_ctor	= ExceptionClass_ctor;
	CAST_CLASS(Object, class)->ctor 		= Exception_ctor;
}


Exception * newException(int value) {
	Exception * obj;

	obj = newObject(ExceptionClass(), OBJ_SIZE(Exception), OBJ_PRIV_OFFSET(Exception), value);

	assert(obj);

	return obj;
}


void Exception_ctor(const void * obj, va_list * app) {

	TYPE_PRIV(Exception) * priv = privOf(obj);

	super_ctor(ExceptionClass(), obj, app);

	priv->value = va_arg(*app,  int);

}

/*Public:*/

void Exception_destroy(const void * obj) {
	if (obj == ThrowException)
		ThrowException = NULL;
	CAST_METH(Object,OBJECT_CLASS(super(ExceptionClass()))->meths)->destroy(obj);
}

int Exception_getValue(const void * obj) {

	TYPE_PRIV(Exception) * priv = privOf(obj);

	return priv->value;
}


