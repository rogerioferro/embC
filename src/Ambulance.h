/*
 * Ambulance.h
 *
 *  Created on: 10 de nov de 2016
 *      Author: Rogério
 */

#ifndef AMBULANCE_H_
#define AMBULANCE_H_

#include "Car.h"

extern Class AmbulanceClass();

/*Object Attributes*/
typedef struct {
	OBJ_EXTENDS(Car);
} Ambulance;

/*Object Methods*/
typedef struct {
	OBJ_EXTENDS_METH(Car);
} TYPE_METH(Ambulance);

/*Object Creator*/
extern Ambulance * newAmbulance();

#endif /* AMBULANCE_H_ */
