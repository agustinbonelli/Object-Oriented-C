/*
 * dog_internal.c
 *
 *  Created on: 18 Nov 2016
 *      Author: bone
 */

#include "animal.h"
#include "animal_internal.h"
#include "dog_internal.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

Dog* internalCreateDog(void)
{
	Dog* object = (Dog*) malloc(sizeof(Dog));
	if(!object)
	{
		return NULL;

	}

	internalCreateAnimalFromAllocatedSpace(&(object->base));

	/** Overwrite the method we desire with our own*/
	object->base.vPtr->saySomething = &internalDogSaySomethingOverrideAnimal;


	/* Initialise member of this derived class*/
	object->race = UnknownRace;

	return object;
}

void internalDestroyDog(Dog* me)
{

}

void internalDogSaySomethingOverrideAnimal(Animal* me)
{
	/*Do container of pointer arithmetic trick to get the Dog pointer*/
	Dog* dog = (Dog*)( (char *)me - offsetof(Dog,base));
	internalDogSaySomething(dog);
}

void internalDogSaySomething(Dog* me)
{
	printf("I am a Dog. The derived Class. And my race value is %u \n",(unsigned int)me->race);
}

void internalDogSetRace(Dog* me,race_t race)
{
	me->race = race;
}


race_t internalDogGetRace(Dog* me)
{
	return me->race;
}
