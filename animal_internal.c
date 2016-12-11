/*
 * animal.c
 *
 *  Created on: 17 Nov 2016
 *      Author: bone
 */

#include "animal_internal.h"
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

Animal* internalCreateAnimal()
{
	Animal* object = (Animal*) malloc(sizeof(Animal));
	if(!object)
	{
		return NULL;
	}

	vTable_Animal* vTable = (vTable_Animal*) malloc(sizeof(vTable_Animal));

	if(!vTable)
	{
		free(object);
		return NULL;
	}

	vTable->saySomething 	= &internalAnimalSaySomething;
	vTable->setAge 			= &internalAnimalSetAge;
	vTable->setGender 		= &internalAnimalSetGender;
	vTable->getAge 			= &internalAnimalGetAge;
	vTable->getGender 		= &internalAnimalGetGender;

	object->vPtr = vTable;
	object->age = 0;
	object->gender = male;

	return object;
}

void internalCreateAnimalFromAllocatedSpace(Animal* object)
{
	assert(NULL != object);

	vTable_Animal* vTable = (vTable_Animal*) malloc(sizeof(vTable_Animal));

	if(!vTable)
	{
		return;
	}

	vTable->saySomething 	= &internalAnimalSaySomething;
	vTable->setAge 			= &internalAnimalSetAge;
	vTable->setGender 		= &internalAnimalSetGender;
	vTable->getAge 			= &internalAnimalGetAge;
	vTable->getGender 		= &internalAnimalGetGender;

	object->vPtr = vTable;
	object->age = 0;
	object->gender = male;

}

void internalDestroyAnimalFromAllocatedSpace(Animal* me)
{
	assert(me);
	free(me->vPtr);
}

void internalDestroyAnimal(Animal* me)
{
	if(me)
	{
		free(me->vPtr);
		free(me);
	}
}

void internalAnimalSaySomething(Animal* me)
{
	printf("I am an Animal. The base Class. And my age is % u\n",me->age);
}

void internalAnimalSetAge(Animal* me,unsigned int age)
{
	me->age = age;
}

void internalAnimalSetGender(Animal* me,gender_t gender)
{
	me->gender = gender;
}

unsigned int internalAnimalGetAge(Animal* me)
{
	return me->age;
}

gender_t internalAnimalGetGender(Animal* me)
{
	return me->gender;
}
