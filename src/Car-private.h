/*
 * Car-private.h
 *
 *  Created on: 10 de nov de 2016
 *      Author: Rogério
 */

#ifndef CAR_PRIVATE_H_
#define CAR_PRIVATE_H_

#include "Object-private.h"
#include "Car.h"


/* Private Methods */
typedef struct {
	OBJ_EXTENDS_CLASS(Object);
} TYPE_CLASS(Car);

/* Private Attributes*/
typedef struct {
	OBJ_EXTENDS_PRIV(Object);
} TYPE_PRIV(Car);


#endif /* CAR_PRIVATE_H_ */
