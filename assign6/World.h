

#include "RandomNum.h"
#include <vector>

class creature;

using namespace std;

class World
{
	enum direction{
		up=0,
		down,
		left,
		right
	};

	public:
		World(int, int);

		void mainLoop(int );

	private:
		void showMap();
		void start();
		bool checkRange(int ,int );
		void moveDi(int ,int ,int &,int &,bool &);
		void onePass(const int);

		static const int row=20;
		static const int col=35;
		RandomNum random;

		char map[row][col]={{'\0'}};
		creature* mapptr[row*col]; 
		int round;
};
