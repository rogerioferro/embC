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
	extends(classPoint);
} classCircle;

/* Private Attributes*/
typedef struct {
	extends(privPoint);
} privCircle;


#endif /* CIRCLE_PRIVATE_H_ */
