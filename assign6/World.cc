#include <iostream>
#include <vector>
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"
#include "World.h"

using namespace std;

World::World(int r,int seed)
	:random(seed)
{
	round=r;
}

void
World::mainLoop(int dis)
{
	for(int k=0;k<round;++k)
	{
		if(k==0)
			this->start();
		else onePass(k);

		if(k%dis==0)
			this->showMap();
	}
}

void 
World::showMap()
{
	for(int i=-1;i<=row;++i)
	{
		if(i<0)
		{
			cout<<" ";
			for(int j=0;j<col;++j)
				cout<<" "<<j%10;
			cout<<endl;
		}
		else if(i==row)
		{
			for(int j=0;j<72;++j)
				cout<<"-";
			cout<<endl;
		}
		else
		{
			cout<<i%10;
			for(int j=0;j<col;++j)
			{
				if (map[i][j]=='\0')
					cout <<"  ";
				else cout<<" "<<map[i][j];
			}
			cout<<endl;
		}
	}
}

void 
World::start()
{
	int tmpx,tmpy;
	for(int i=0;i<15;++i)
	{
		while(true)
		{
			tmpx=random.getRandomNum(0,row-1);
			tmpy=random.getRandomNum(0,col-1);
			if(map[tmpx][tmpy]=='\0')
				break;
		}

		if(i<5)
		{
			map[tmpx][tmpy]='X';
			mapptr[tmpx*35+tmpy]=new goat(1);
		}

		else
		{
			map[tmpx][tmpy]='I';
			mapptr[tmpx*35+tmpy]=new grass(1);
		}
	}
}

bool 
World::checkRange(int p,int q)
{
	if(p<0 || p>=row)
		return false;
	if(q<0 || q>=col)
		return false;
	return true;
}

void
World::moveDi(int i,int j,int &x,int &y,bool &move)
{
	int tmp;
	tmp=random.getRandomNum(0,3);
    switch(tmp)
    {
        case up:
			if(map[i-1][j]!='X' && checkRange(i-1,j)==true)
        	{
            	x=i-1;
				y=j;
				move=true;
			}
			break;
		case down:
			if(map[i+1][j]!='X' && checkRange(i+1,j)==true)
            {
                x=i+1;
				y=j;
				move=true;
			}
			break;
		case left:
			if(map[i][j-1]!='X' && checkRange(i,j-1)==true)
			{
				x=i;
				y=j-1;
				move=true;
			}
			break;
		case right:
			if(map[i][j+1]!='X' && checkRange(i,j+1)==true)
			{
				x=i;
				y=j+1;
				move=true;
			}
			break;
	}
}

void 
World::onePass(const int r)
{
	int x,y;
	bool move;
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;++j)
		{
			if(map[i][j]=='\0' || mapptr[i*35+j]->getPass()==r)
				continue;

		//goat
			move=false;
			if(map[i][j]=='X')
			{
				if(mapptr[i*35+j]->getAge()==70 || mapptr[i*35+j]->getFoodPoint()==0)
				{
					mapptr[i*35+j]=NULL;
					map[i][j]='\0';
				}

				else if (mapptr[i*35+j]->getAge()>=50 && mapptr[i*35+j]->getAge()<=55)
				{
					mapptr[i*35+j]->endPass(r);
					//give birth
					moveDi(i,j,x,y,move);
					if(move==true)
					{
						if(map[x][y]=='I')
                        {   
                            mapptr[i*35+j]->eatGrass();
                            mapptr[x*35+y]=NULL;
							map[x][y]='\0';
                        }
						map[x][y]='X';
                        mapptr[x*35+y]=new goat(r);
					}
					//
				}

				else 
				{	
					mapptr[i*35+j]->endPass(r);

					//move
					moveDi(i,j,x,y,move);
					if(move==true)
					{
						if(map[x][y]=='I')
						{
							mapptr[i*35+j]->eatGrass();
							mapptr[x*35+y]=NULL;
							map[x][y]='\0';
						}
						map[i][j]='\0';
						
						map[x][y]='X';
						
						mapptr[x*35+y]=mapptr[i*35+j];
						
						mapptr[i*35+j]=NULL;
						
					}
					//
				}
			}
		//end of goat
		//grass
			else if (map[i][j]=='I')
			{
				if(mapptr[i*35+j]->getAge()==6)
				{
					map[i][j]='\0';
					mapptr[i*35+j]=NULL;
				}
				
				else if (mapptr[i*35+j]->getAge()>=3 && mapptr[i*35+j]->getAge()<=5)
				{
					mapptr[i*35+j]->endPass(r);
					//give birth
					moveDi(i,j,x,y,move);
                    if(move==true)
                    {
                        if(map[x][y]!='I')
                        {
                        	map[x][y]='I';
                        	mapptr[x*35+y]=new grass(r);
						}
                    }
					//
				}
				else
					mapptr[i*35+j]->endPass(r);
			}
		//end of grass
		}
	}
}
