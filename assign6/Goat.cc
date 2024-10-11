#include "Creature.h"
#include "Goat.h"

goat::goat(int p=0)
{
	foodPoint=20;
	pass=p;
}

goat::~goat(){}

void
goat::endPass(int p)
{
	pass=p;
	older();
	foodPoint--;
}

int 
goat::getPass() const
{
	return pass;
}

int 
goat::getFoodPoint() const
{
	return foodPoint;
}

void
goat::eatGrass() 
{
	foodPoint+=5;
}
