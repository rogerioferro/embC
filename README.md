# embC

embC is a Design Pattern to implements object-oriented design in pure Ansi C.
Is possible to implements these common features:

1. Object/Class;
2. Information hide (Public/Private);
3. Inheritance;
4. Interface;
5. Polymorphism.

## Overview

The core files that implements Object/Class mechanism are:

* Object-macros.h : Contain the macros to help the design be more clean em less verbose.
* Object-private.h : Contain the private declaration of **Object** 
* Object.h : Contain the public declaration of **Object**
* Object.c : Contain the implementation on **Object**

All new **Class** should inherite **Object** and have to implement 3 files like **Point** at the example:

* Point-private.h
* Point.h
* Point.c

The **main.c** implements a vector of 10 **Object** of different **Class** and apply some algorithm to all of them, without know its **type**:

```c
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
```
That produce these output:
```
--- Object 0 ---
circle at 1,2 rad 3
Point moving...
circle at 11,22 rad 3
--- Object 1 ---
Vrummm! Vrummm!
Car Running...
--- Object 2 ---
weeeoooeee! weeeoooeee!
Ambulance Running...
--- Object 3 ---
"." at 3,8
Point moving...
"." at 13,28
--- Object 4 ---
Vrummm! Vrummm!
Car Running...
--- Object 5 ---
weeeoooeee! weeeoooeee!
Ambulance Running...
--- Object 6 ---
"." at 4,5
Point moving...
"." at 14,25
--- Object 7 ---
Vrummm! Vrummm!
Car Running...
--- Object 8 ---
circle at 3,7 rad 5
Point moving...
circle at 13,27 rad 5
--- Object 9 ---
weeeoooeee! weeeoooeee!
Ambulance Running...
```
As you can see, each object only executes the interface it implements. 
The object **Circle** execute the **Point** interface because it is his child.
**Sound** is an interface and the object **Car** implement it.
**Ambulance** is a **Car** child, than it inherits its interfaces.


