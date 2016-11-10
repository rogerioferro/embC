/*
 * Car.c
 *
 *  Created on: 10 de nov de 2016
 *      Author: Rogério
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "Car-private.h"


/* Declare Private Object*/
OBJ_DECLARE(Car);

/*
 *  Declarations
 **/

Car * 			newCar				();
void 			CarClass_ctor		(void * class, void * meth);
const void * 	Car_getInterface	(void * obj, Class class);
void 			Car_run 			(const void * obj);
void 			Car_make_noise  	(const void * obj);


/*
 *  Implementations
 **/



/* Class Definition function
 *
 *   The function Name MUST be [Object name]Class
 *   MUST call OBJ_START_CLASS macro
 *
 * */
Class CarClass() {
	OBJ_START_CLASS(Car);
}


/* Class Constructor:
 *
 *   The function name MUST be [Object name]Class_ctor
 *   This function is called on the first call of [Object name]Class()
 *   Should call the Class Constructor of SUPER Class and
 *     fill up the object with his own parameters
 *
 * */
void CarClass_ctor(void * class, void * meth) {

/* Call Class Constructor of the SUPER Class */
	superClass_ctor(ObjectClass(), class, meth);

/* Fill up Object Parameters*/

	/* Public Methods*/
	CAST_METH(Car, meth)->run	=	Car_run;


	/* Sound Interface*/
	CAST_METH(Car, meth)->sound_meth.make_noise	=	Car_make_noise;

	/*Private Methods*/
	CAST_CLASS(Object, class)->super 		= ObjectClass();
	CAST_CLASS(Object, class)->class_ctor	= CarClass_ctor;
	CAST_CLASS(Object, class)->getInterface = Car_getInterface;
}


Car * newCar() {
	Car * obj;

	obj = newObject(CarClass(), OBJ_SIZE(Car));
	assert(obj);

	return obj;
}

const void * Car_getInterface(void * obj, Class class){

	if (class == SoundClass())
		return & CAST_METH(Car, CAST_PRIV(Object,privOf(obj))->meths)->sound_meth;

	return OBJECT_CLASS(ObjectClass())->getInterface(obj, class);
}


/* Sound Interface*/

void Car_make_noise (const void * obj){

	printf ("Vrummm! Vrummm!\n");
}

/*Public:*/

void Car_run (const void * obj){

	printf ("Car Running...\n");
}
