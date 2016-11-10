/*
 * CircleProtect.h
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#ifndef CIRCLE_PRIVATE_H_
#define CIRCLE_PRIVATE_H_

#include "Circle.h"
#include "Point-private.h"

/* Private Methods */
typedef struct {
	OBJ_EXTENDS_CLASS(Point);

} TYPE_CLASS(Circle);

/* Private Attributes*/
typedef struct {
	OBJ_EXTENDS_PRIV(Point);

} TYPE_PRIV(Circle);

#endif /* CIRCLE_PRIVATE_H_ */
