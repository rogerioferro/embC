/*
 * PointProtect.h
 *
 *  Created on: 6 de nov de 2016
 *      Author: Rogério
 */

#ifndef POINT_PRIVATE_H_
#define POINT_PRIVATE_H_

#include "Object-private.h"
#include "Point.h"

/* Private Attributes*/
typedef struct {
	extends(privObject);
} privPoint;

/* Private Methods */
typedef struct {
	extends(classObject);
} classPoint;


#endif /* POINT_PRIVATE_H_ */
