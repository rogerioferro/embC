/*
 * Object.c
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#include <assert.h>
#include <stdlib.h>


#include "Object-private.h"

/* Declare Private Object*/
OBJ_DECLARE(Object);

/*
 *  Declarations
 **/

void * 			newObject			(const void * class, ...);

/*Private Methods*/
void 			ObjectClass_ctor	(void * _meths_, void * meths_);
void 			Object_ctor			(const void * obj, va_list * app);
const void *	Object_getInterface	(const void * obj, Class class);

/*Public Methods*/
void 			Object_destroy		(const void * obj);

/*
 *  Implementations
 **/

/* Class Definition function
 *
 *   The function Name MUST be [Object name]Class
 *   MUST call OBJ_START_CLASS macro
 *
 * */
Class ObjectClass() {
	OBJ_START_CLASS(Object);
}

void ObjectClass_ctor(void * class, void * meths) {

	/* Public Methods*/
	CAST_METH(Object,meths)->destroy	= Object_destroy;

	/*Private Methods*/
	CAST_CLASS(Object,class)->super 		= NULL;
	CAST_CLASS(Object,class)->meths 		= meths;
	CAST_CLASS(Object,class)->class_ctor 	= ObjectClass_ctor;
	CAST_CLASS(Object,class)->ctor 			= Object_ctor;
	CAST_CLASS(Object,class)->getInterface	= Object_getInterface;
}

void * newObject(const void * class, ...) {
	Object * 	obj;
	va_list 	ap;
	size_t		obj_size, priv_offset;

	va_start(ap, class);

	obj_size	=	va_arg(ap, size_t);
	priv_offset	=	va_arg(ap, size_t);

	obj			= malloc(obj_size);

	assert(obj);

	obj->_class	= class;
	obj->_priv	= (void *)((size_t)obj + priv_offset);

	CAST_PRIV(Object,privOf(obj))->meths = CAST_CLASS(Object,class)->meths;

	OBJECT_CLASS(class)->ctor(obj, &ap);

	va_end(ap);

	return obj;
}

void Object_ctor(const void * obj, va_list * app) {
	assert(obj);
}

const void * Object_getInterface(const void * obj, Class class) {
	if (isOf(obj, class)) {
		return CAST_PRIV(Object,privOf(obj))->meths;
	}
	return NULL;
}

void Object_destroy(const void * obj) {

	if ( isOf( obj, ObjectClass() ) ){
		free((void *)obj);
	}
}


/*
 * PROTECT:
 *
 * */
bool  isOf(const void * obj, Class class) {

	const TYPE_CLASS(Object) * obj_class;

	assert(obj && class);

	obj_class = classOf(obj);

	while (obj_class) {
		if (obj_class == class)
			return true;
		obj_class = obj_class->super;
	}
	return false;
}


/*
 * PUBLIC:
 * ObjIterface Selector
 * */
const void * Interface(const void * obj, Class class) {
	assert(obj && class);
	if (isOf(obj,ObjectClass())){
		const TYPE_CLASS(Object) * obj_class;
		obj_class = classOf(obj);
		assert(obj_class);
		return obj_class->getInterface(obj, class);
	}
	return NULL;
}


void Destroy(const void * obj){
	if (isOf(obj,ObjectClass())){
		CAST_METH(Object, methOf(obj))->destroy(obj);
	}
}
