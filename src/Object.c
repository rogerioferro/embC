/*
 * Object.c
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#include <assert.h>
#include <stdlib.h>

#include "Object-private.h"

/* Private Object*/
typedef struct {
	Object pub;
	privObject priv;
} _Object;

/*
 *  Declarations
 **/

void * 			newObject			(const void * class, ...);

/*Private Methods*/
void 			ObjectClass_ctor	(void * _meths_, void * meths_);
void 			Object_ctor			(void * obj, va_list * app);
const void *	Object_getInterface	(void * obj, Class class);

/*Public Methods*/
void 			Object_destroy		(void * obj);

/*
 *  Implementations
 **/

Class ObjectClass() {
	static TYPE_METH(Object) meths; /* Public Methods */
	static TYPE_CLASS(Object) class; /* Private Methods */
	static Class pClass = NULL;

	if (!pClass) {
		pClass = &class;
		ObjectClass_ctor(&class, &meths);
	}
	return pClass;
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
	Object * obj;
	size_t obj_size;
	va_list ap;

	va_start(ap, class);
	obj_size	= va_arg(ap, size_t);
	obj			= calloc(1, obj_size);

	assert(obj);

	obj->_class	= class;
	obj->_priv	= (const void *) ((size_t) obj + obj_size - sizeof(void *));

	CAST_PRIV(Object,privOf(obj))->meths = CAST_CLASS(Object,class)->meths;

	CAST_CLASS(Object,class)->ctor(obj, &ap);

	va_end(ap);

	return obj;
}

void Object_ctor(void * obj, va_list * app) {
	assert(obj);
	printf("Object_ctor...\n");
}

const void * Object_getInterface(void * obj, Class class) {
	if (isOf(obj, class)) {
		return CAST_PRIV(Object,privOf(obj))->meths;
	}
	return NULL;
}

void Object_destroy(void * obj) {

	if ( isOf( obj, ObjectClass() ) )
		free(obj);

}


/*
 * PROTECT:
 *
 * */
const void * isOf(void * obj, Class class) {

	const TYPE_CLASS(Object) * obj_class;

	assert(obj && class);

	obj_class = classOf(obj);

	while (obj_class) {
		if (obj_class == class)
			return class;
		obj_class = obj_class->super;
	}
	return NULL;
}


/*
 * PUBLIC:
 * ObjIterface Selector
 * */
const void * Interface(void * obj, Class class) {
	const TYPE_CLASS(Object) * obj_class = classOf(obj);
	assert(obj && class);
	return obj_class->getInterface(obj, class);
}

