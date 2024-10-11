#include "Creature.h"
#include "Grass.h"

grass::grass(int p=0)
{
	pass=p;
}

grass::~grass()
{
}

void 
grass::endPass(int p)
{
	pass=p;
	older();
}

int
grass::getPass() const
{
	return pass;
}

//
int 
grass::getFoodPoint() const{return 0;}

void
grass::eatGrass(){}
