/*
 * animal.h
 *
 *  Created on: 18 Nov 2016
 *      Author: bone
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

typedef enum
{
	male = 0,
	female
}gender_t;

typedef void* Animal_t;

Animal_t CreateAnimal(void);

void DestroyAnimal(Animal_t me);

void AnimalSaySomething(Animal_t me);

void AnimalSetAge(Animal_t me,unsigned int age);

void AnimalSetGender(Animal_t me,gender_t gender);

unsigned int AnimalGetAge(Animal_t me);

gender_t AnimalGetGender(Animal_t me);

#endif /* ANIMAL_H_ */
