#include <iostream>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;

int main()
{
	int i;
	char str[20];
	for(i=0;i<11;++i)
	{
		sprintf(str,"%s",card[1][i]);
		AnsiPrint(str,black,white, false, false);
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
