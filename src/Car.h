/*
 * Car.h
 *
 *  Created on: 10 de nov de 2016
 *      Author: Rogério
 */

#ifndef CAR_H_
#define CAR_H_

#include "Object.h"


/* implements Sound Interface*/
#include "Sound.h"

extern Class CarClass();

/*Object Attributes*/
typedef struct {
	OBJ_EXTENDS(Object);
} Car;

/*Object Methods*/
typedef struct {
	OBJ_EXTENDS_METH(Object);
	/*Implement Sounds*/
	TYPE_METH(Sound) sound_meth;

	void (*run)(const void * obj);
} TYPE_METH(Car);

/*Object Creator*/
extern Car * newCar();

#endif /* CAR_H_ */
