/*
 * ObjectPrivate.h
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#ifndef OBJECT_PRIVATE_H_
#define OBJECT_PRIVATE_H_

#include <stdarg.h>
#include <stddef.h>
#include "Object.h"
#include "Object-macros.h"

/* Private Methods */
typedef struct {
	const void *	super; /* super class */
	const void * 	meths; /* public methods */

/* protected members */

	/* Constructors */
	void (*class_ctor)(void * class, void * meths);
	void (*ctor)(const void * obj, va_list * app);
	/* return the Class interface if implemented */
	const void * (*getInterface)(const void * obj, Class class);

} TYPE_CLASS(Object);

/* Private Attributes*/
typedef struct {
	const void * meths; /*Object Methods*/
} TYPE_PRIV(Object);



#define OBJECT(x)			CAST(Object,x)
#define OBJECT_CLASS(x)		CAST_CLASS(Object,x)



/* Protect Members */

/* Create a new Object
 *    Must pass the Class descriptor and the OBJ_SIZE
 *    pass the constructor of arguments at sequence
 *
 * */
extern void * newObject (const void * _class, ...);

/* Check if obj is of class
 *
 * */
extern bool isOf (const void * obj, Class class);

#endif /* OBJECT_PRIVATE_H_ */
