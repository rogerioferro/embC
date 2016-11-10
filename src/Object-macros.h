/*
 * Object-macros.h
 *
 *  Created on: 10 de nov de 2016
 *      Author: Rogério
 */

#ifndef OBJECT_MACROS_H_
#define OBJECT_MACROS_H_



#define TYPE_OBJ(obj_type)		_##obj_type
#define TYPE_CLASS(obj_type)	class##obj_type
#define TYPE_PRIV(obj_type)		priv##obj_type

#define CAST_CLASS(obj_type,var)	((TYPE_CLASS(obj_type) *)(var))
#define CAST_PRIV(obj_type,var)		((TYPE_PRIV(obj_type) *)(var))

#define privOf(o)	(OBJECT(o)->_priv)
#define classOf(o)	(OBJECT(o)->_class)

#define super_ctor(class, obj, app)				CAST_CLASS(Object,OBJECT_CLASS(class)->super)->ctor(obj, app)
#define superClass_ctor(super, class, inter) 	CAST_CLASS(Object,super)->class_ctor(class, inter)

#define OBJ_DECLARE(x) 	typedef struct {x pub; TYPE_PRIV(x) priv;}TYPE_OBJ(x)
#define OBJ_SIZE(x)		sizeof(TYPE_OBJ(x))

#define OBJ_EXTENDS_CLASS(x)	TYPE_CLASS(x) _
#define OBJ_EXTENDS_PRIV(x)		TYPE_PRIV(x) _


/* Macro to be put on Class Definition.
 * Static create the Class Struct and call
 *  Constructor Class to Fill it up.
 * */
#define OBJ_START_CLASS(x)					\
	do{										\
		static TYPE_METH(x) meth;			\
		static TYPE_CLASS(x) class;			\
		static Class pClass = NULL;			\
		if (!pClass) {						\
			pClass = &class;				\
			x##Class_ctor(&class, &meth);	\
		}									\
		return pClass;						\
	}while(0)


#endif /* OBJECT_MACROS_H_ */
