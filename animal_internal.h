/*
 * animal_internal.h
 *
 *  Created on: 17 Nov 2016
 *      Author: bone
 */

#ifndef ANIMAL_INTERNAL_H_
#define ANIMAL_INTERNAL_H_

#include "animal.h"

typedef struct Animal_s
{
	struct vTable_Animal_s* vPtr;
	unsigned int age;
	gender_t gender;
}Animal;

typedef struct vTable_Animal_s
{
	void 			(*saySomething)	(Animal* me); /*Virtual*/
	void 			(*setAge)		(Animal* me,unsigned int age);
	void 			(*setGender)	(Animal* me,gender_t gender);
	unsigned int	(*getAge)		(Animal* me);
	gender_t 		(*getGender)	(Animal* me);
}vTable_Animal;

Animal* internalCreateAnimal(void);

void internalCreateAnimalFromAllocatedSpace(Animal* object);

void internalDestroyAnimal(Animal* me);

void internalDestroyAnimalFromAllocatedSpace(Animal* me);

/*Virtual*/ void internalAnimalSaySomething(Animal* me);

/*Virtual*/ void internalAnimalSetAge(Animal* me,unsigned int age);

/*Virtual*/ void internalAnimalSetGender(Animal* me,gender_t gender);

/*Virtual*/ unsigned int internalAnimalGetAge(Animal* me);

/*Virtual*/ gender_t internalAnimalGetGender(Animal* me);



#endif /* ANIMAL_INTERNAL_H_ */
