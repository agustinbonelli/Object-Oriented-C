/*
 * animal.c
 *
 *  Created on: 18 Nov 2016
 *      Author: bone
 */

#include "animal.h"
#include "animal_internal.h"

Animal_t CreateAnimal(void)
{
	return internalCreateAnimal();
}

void DestroyAnimal(Animal_t me)
{
	if(me)
	{
		internalDestroyAnimal(me);
	}
}

void AnimalSaySomething(Animal_t me)
{
	if(me)
	{
		Animal* object = (Animal*) me;
		object->vPtr->saySomething(object);
	}
}

void AnimalSetAge(Animal_t me,unsigned int age)
{
	if(me)
	{
		Animal* object = (Animal*) me;
		object->vPtr->setAge(object,age);
	}
}

void AnimalSetGender(Animal_t me,gender_t gender)
{
	if(me)
	{
		Animal* object = (Animal*) me;
		object->vPtr->setGender(object,gender);
	}
}

unsigned int AnimalGetAge(Animal_t me)
{
	if(!me)
	{
		/** Return a non valid age value*/
		return ~0;
	}
	else
	{
		Animal* object = (Animal*) me;
		return object->vPtr->getAge(object);
	}
}

gender_t AnimalGetGender(Animal_t me)
{
	if(!me)
	{
		/** Return a non valid age value*/
		return ~0;
	}
	else
	{
		Animal* object = (Animal*) me;
		return object->vPtr->getGender(object);
	}
}
