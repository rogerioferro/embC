/*
 ============================================================================
 Name        : my_circles.c
 Author      : Rogério Ferro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>

#include "Circle.h"
#include "Ambulance.h"

#define MAX	10

int main(int argc, char ** argv) {
	void * objs[MAX];
	objs[0] = newCircle(1, 2, 3);
	objs[1] = newCar();
	objs[2] = newAmbulance();
	objs[3] = newPoint(3, 8);
	objs[4] = newCar();
	objs[5] = newAmbulance();
	objs[6] = newPoint(4, 5);
	objs[7] = newCar();
	objs[8] = newCircle(3, 7, 5);
	objs[9] = newAmbulance();


	{
		int i;
		const void * meths;
		for(i = 0; i < MAX; i++) {
			printf("--- Object %d ---\n", i);
			meths = Interface(objs[i], PointClass());
			if (meths) {
				CAST_METH(Point,meths)->draw(objs[i]);
				CAST_METH(Point,meths)->move(objs[i], 10, 20);
				CAST_METH(Point,meths)->draw(objs[i]);
			}
			meths = Interface(objs[i], SoundClass());
			if (meths) {
				CAST_METH(Sound,meths)->make_noise(objs[i]);
			}
			meths = Interface(objs[i], CarClass());
			if (meths) {
				CAST_METH(Car,meths)->run(objs[i]);
			}
			meths = Interface(objs[i], ObjectClass());
			CAST_METH(Object,meths)->destroy(objs[i]);
		}
	}

	return 0 ;
}
