/*
 * dog_internal.h
 *
 *  Created on: 18 Nov 2016
 *      Author: bone
 */

#ifndef DOG_INTERNAL_H_
#define DOG_INTERNAL_H_

#include "dog.h"
#include "animal_internal.h"

typedef struct Dog_s
{
	race_t race;
	Animal base; /*Inherit from Animal*/
}Dog;

typedef struct vTable_Dog_s
{
	void 			(*saySomething)	(); /*Virtual*/
	void 			(*setAge)		(Animal* me,unsigned int age);
	void 			(*setGender)	(Animal* me,gender_t gender);
	unsigned int	(*getAge)		(Animal* me);
	gender_t 		(*getGender)	(Animal* me);
	race_t			(*getRace)		(Dog* me);
	void			(*setRace)		(Dog* me,race_t race);
}vTable_Dog;

Dog* internalCreateDog(void);

void internalDestroyDog(Dog* me);

void internalDogSaySomethingOverrideAnimal(Animal* me);

void internalDogSaySomething(Dog* me);

void internalDogSetRace(Dog* me,race_t race);

race_t internalDogGetRace(Dog* me);


#endif /* DOG_INTERNAL_H_ */
