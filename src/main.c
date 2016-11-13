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
#include <signal.h>

#include "Circle.h"
#include "Ambulance.h"
#include "Exception.h"


#define MAX	10

void sighandler(int signum)
{
   printf("Caught signal %d, coming out...\n", signum);
   exit(1);
}

void printException(char* function, Exception * exc){
	if (exc){
		const void * m;
		m = Interface(exc, ExceptionClass());
		printf("%s: catch exception: %d\n",function, CAST_METH(Exception, m)->getValue(exc));
	}
}

void func2() throws(Exception){
 	Exception * exception;

 	printf("func2: Entering...\n");

 	exception = newException(2);

	throw(exception);

	printf("func2: Exiting...\n");

	return;
}

void func1(int arg) throws(Exception){
	Exception * exception;

 	printf("func1: Entering...\n");

	try{
 		if (arg == 0)
 			func2();
 	}
 	catch(exception){
 		printException("func1",exception);
 	}
 	finally{
  		printf("func1: finally...\n");
 	}endtry;

 	if(arg == 1){
		Exception * e = newException(1);
 		throw(e);
 	}

 	if(arg == 2){
 		func2();
 	}

	printf("func1 Exiting...\n");
}


int main(int argc, char ** argv) {
	void * objs[MAX];

	signal(SIGSEGV, sighandler);

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

	printf("===== INTERFACE TEST =====\n");
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
			Destroy(objs[i]);
		}
	}

	printf("===== TRY..CATCH TEST =====\n");
	{
		Exception * exception;
		printf("--- Try 1 ---\n");
		try{
			func1(0);
		}catch(exception){
	 		printException("main",exception);
		}endtry;


		printf("--- Try 2 ---\n");
		try{
			func1(1);
		}catch(exception){
	 		printException("main",exception);
		}endtry;


		printf("--- Try 3 ---\n");
		try{
			func2();
		}catch(exception){
	 		printException("main",exception);
		}endtry;

		printf("--- Try 4 ---\n");
		try{
			func1(2);
		}catch(exception){
	 		printException("main",exception);
		}endtry;
	}

	return 0 ;
}
