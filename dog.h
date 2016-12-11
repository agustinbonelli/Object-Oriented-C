/*
 * dog.h
 *
 *  Created on: 18 Nov 2016
 *      Author: bone
 */

#ifndef DOG_H_
#define DOG_H_

#include "animal.h"

typedef enum
{
	UnknownRace = 0,
	Labrador,
	Collie,
	German_Sheperd,
}race_t;

typedef void* Dog_t;

Dog_t CreateDog(void);

void DestroyDog(Dog_t me);

void DogSaySomething(Dog_t me);

void DogSetRace(Dog_t me,race_t race);

race_t DogGetRace(Dog_t me);

Animal_t DogTransformToAnimal(Dog_t me);

#endif /* DOG_H_ */
