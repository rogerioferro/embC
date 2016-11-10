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

/* Private Methods */
typedef struct classObject {
	const struct classObject *	super; /* super class */
	const void * 				meths; /* public methods */

/* protected members */

	/* Constructors */
	void (*class_ctor)(void * class, void * meths);
	void (*ctor)(void * obj, va_list * app);
	/* return the Class interface if implemented */
	const void * (*getInterface)(void * obj, Class class);
} classObject;

/* Private Attributes*/
typedef struct {
	const void * meths; /*Object Methods*/
} privObject;

#define TYPE_CLASS(obj_type)	class##obj_type
#define TYPE_PRIV(obj_type)		priv##obj_type

#define CAST_CLASS(obj_type,var)	((TYPE_CLASS(obj_type) *)(var))
#define CAST_PRIV(obj_type,var)		((TYPE_PRIV(obj_type) *)(var))


#define OBJECT(x)			CAST(Object,x)
#define OBJECT_CLASS(x)		CAST_CLASS(Object,x)

#define privOf(o)			(OBJECT(o)->_priv)
#define classOf(o)			(OBJECT(o)->_class)

#define super_ctor(class, obj, app)				OBJECT_CLASS(class)->super->ctor(obj, app)
#define superClass_ctor(super, class, inter) 	CAST_CLASS(Object,super)->class_ctor(class, inter)


/* Protect Attributes */
extern methObject ObjectMethods;

/* Protect Members */
extern void * newObject(const void * _class, ...);
extern const void * isOf(void * obj, Class class);

#endif /* OBJECT_PRIVATE_H_ */
