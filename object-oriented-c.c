/*
 ============================================================================
 Name        : object-oriented-c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "dog.h"
#include "animal.h"

int main(void)
{
	int i = 0;
	Animal_t animals[3];

	Animal_t Bob = CreateAnimal();
	Dog_t pete = CreateDog();
	Dog_t steph = CreateDog();

	AnimalSetAge(Bob,10);

	AnimalSetAge(DogTransformToAnimal(pete),20);

	AnimalSetAge(DogTransformToAnimal(steph),30);

	DogSetRace(pete,Labrador);
	DogSetRace(steph,German_Sheperd);

	animals[0] = DogTransformToAnimal(pete);
	animals[1] = Bob;
	animals[2] = DogTransformToAnimal(steph);

	for (i = 0; i < 3; ++i)
	{
		AnimalSaySomething(animals[i]);
	}

	DestroyDog(Bob);
	DestroyDog(pete);
	DestroyDog(steph);
	return 0;
}
