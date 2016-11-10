/*
 * Ambulance-private.h
 *
 *  Created on: 10 de nov de 2016
 *      Author: Rogério
 */

#ifndef AMBULANCE_PRIVATE_H_
#define AMBULANCE_PRIVATE_H_


#include "Car-private.h"
#include "Ambulance.h"

/* Private Methods */
typedef struct {
	OBJ_EXTENDS_CLASS(Car);
} TYPE_CLASS(Ambulance);

/* Private Attributes*/
typedef struct {
	OBJ_EXTENDS_PRIV(Car);
} TYPE_PRIV(Ambulance);

#endif /* AMBULANCE_PRIVATE_H_ */
