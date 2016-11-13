/*
 * Exception-private.h
 *
 *  Created on: 12 de nov de 2016
 *      Author: Rogério
 */

#ifndef EXCEPTION_PRIVATE_H_
#define EXCEPTION_PRIVATE_H_


#include "Object-private.h"
#include "Exception.h"


/* Private Methods */
typedef struct {
	OBJ_EXTENDS_CLASS(Object);
} TYPE_CLASS(Exception);

/* Private Attributes*/
typedef struct {
	OBJ_EXTENDS_PRIV(Object);
	int value;
} TYPE_PRIV(Exception);




#endif /* EXCEPTION_PRIVATE_H_ */
