#include "Creature.h"

creature::creature()
{
	age=0;
}

creature::~creature(){}

void
creature::older()
{
	age++;
}

int
creature::getAge() const
{
	return age;
}
