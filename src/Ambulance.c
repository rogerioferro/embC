/*
 * Ambulance.c
 *
 *  Created on: 10 de nov de 2016
 *      Author: Rogério
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


#include "Ambulance-private.h"

/* Declare Private Object*/
OBJ_DECLARE(Ambulance);

/*
 *  Declarations
 **/

Ambulance * 	newAmbulance			();
void 			AmbulanceClass_ctor		(void * class, void * meth);
void 			Ambulance_run 			(const void * obj);
void 			Ambulance_make_noise  	(const void * obj);


/*
 *  Implementations
 **/



/* Class Definition function
 *
 *   The function Name MUST be [Object name]Class
 *   MUST call OBJ_START_CLASS macro
 *
 * */
Class AmbulanceClass() {
	OBJ_START_CLASS(Ambulance);
}


/* Class Constructor:
 *
 *   The function name MUST be [Object name]Class_ctor
 *   This function is called on the first call of [Object name]Class()
 *   Should call the Class Constructor of SUPER Class and
 *     fill up the object with his own parameters
 *
 * */
void AmbulanceClass_ctor(void * class, void * meth) {

/* Call Class Constructor of the SUPER Class */
	OBJECT_CLASS(CarClass())->class_ctor(class, meth);

/* Fill up Object Parameters*/

	/* Public Methods*/
	CAST_METH(Car, meth)->run	=	Ambulance_run;


	/* Sound Interface*/
	CAST_METH(Car, meth)->sound_meth.make_noise	=	Ambulance_make_noise;

	/*Private Methods*/
	CAST_CLASS(Object, class)->super 		= CarClass();
	CAST_CLASS(Object, class)->class_ctor	= AmbulanceClass_ctor;
}


Ambulance * newAmbulance() {
	Ambulance * obj;

	obj = newObject(AmbulanceClass(), OBJ_SIZE(Ambulance));
	assert(obj);

	return obj;
}

/* Sound Interface*/

void Ambulance_make_noise (const void * obj){

	printf ("weeeoooeee! weeeoooeee!\n");
}

/*Public:*/

void Ambulance_run (const void * obj){

	printf ("Ambulance Running...\n");
}

