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



/* Private Methods */
typedef struct {
	OBJ_EXTENDS_CLASS(Object);

} TYPE_CLASS(Point);


/* Private Attributes*/
typedef struct {
	OBJ_EXTENDS_PRIV(Object);

} TYPE_PRIV(Point);



#endif /* POINT_PRIVATE_H_ */
