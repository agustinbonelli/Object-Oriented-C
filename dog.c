/*
 * dog.c
 *
 *  Created on: 18 Nov 2016
 *      Author: bone
 */

#include "dog.h"
#include "dog_internal.h"
#include <stddef.h>
#include <assert.h>

Dog_t CreateDog(void)
{
	return internalCreateDog();
}

void DestroyDog(Dog_t me)
{
	if(me)
	{
		internalDestroyDog(me);
	}
}

void DogSaySomething(Dog_t me)
{
	internalDogSaySomething(me);
}

void DogSetRace(Dog_t me,race_t race)
{
	internalDogSetRace(me,race);
}

race_t DogGetRace(Dog_t me)
{
	race_t dogRace = UnknownRace;

	dogRace = internalDogGetRace(me);

	return dogRace;
}

Animal_t DogTransformToAnimal(Dog_t me)
{
	assert(NULL != me);
	return &(((Dog*)me)->base);
}
