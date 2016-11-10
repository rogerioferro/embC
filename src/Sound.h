/*
 * Sound.h
 *
 *  Created on: 10 de nov de 2016
 *      Author: Rogério
 */

#ifndef SOUND_H_
#define SOUND_H_

#include "Object.h"

/* This Class is an Interface doesn't have Attributes*/

extern Class SoundClass();

/*Object Methods*/
typedef struct {
	void (*make_noise) (const void * obj);
} TYPE_METH(Sound);


#endif /* SOUND_H_ */
