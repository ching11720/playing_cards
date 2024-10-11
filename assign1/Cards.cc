/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
  NAME
  Cards.cc
  NOTE
  You are asked to design this module.
  You need to draw the given number of cards and print them out.
  Assume that you are given a deck of 52 cards. The cards do not reappear.
  That is, you do not put a card back into the deck after it is drawn.
 ***************************************************************************/

#include <iostream>
#include "Cards.h"
#include "AnsiPrint.h"

using namespace std;

int draw_cards(int cardnum)
{
	//draw cards//
	int count3,count4,temp1;
	int chosen[52];
	for(count3=0;count3<cardnum;++count3)
	{
redraw:
		temp1=rand()%52;
		for(count4=0;count4<count3;++count4)
		{
			if(temp1==chosen[count4])//check for duplicates//
				goto redraw;
		}
		chosen[count3]=temp1;
	}
	//

	//print card//
	int count1,count2,count5,count6,test5;
	int suit[5],pip[5];
	char cardstr[5];
	char suit_letter[]="SHDC";

	for(count5=0;count5<cardnum;count5=count5+5)
	{
		//chack cardnum over 5 or not//
		test5=(cardnum-count5)/5;
		if(test5>0)
			test5=5;
		else if(test5==0)
			test5=(cardnum-count5)%5;
		//record the suit&pip of the 5 cards//
		for(count6=0;count6<test5;++count6)
		{
			suit[count6]=chosen[count5+count6]/kNPip;//0->S;1->H;2->D;3->C//
			pip[count6]=chosen[count5+count6]%kNPip;
		}

		//from the first column to 11th//
		for(count1=0;count1<kCardHeight;++count1)
		{
			//from the 1st card to the 5th//
			for(count6=0;count6<test5;++count6)
			{
				for(count2=0;count2<kCardWidth;++count2)
				{
					if(card[pip[count6]][count1][count2]=='x')
					{
						sprintf(cardstr,"%c",suit_letter[suit[count6]]);
						if (suit[count6]==0||suit[count6]==3)
							AnsiPrint(cardstr,black,white, false, false);
						else if (suit[count6]==1||suit[count6]==2)
							AnsiPrint(cardstr,red,white, false, false);
					}
					else
					{
						sprintf(cardstr,"%c",card[pip[count6]][count1][count2]);
						if (suit[count6]==0||suit[count6]==3)
							AnsiPrint(cardstr,black,white, false, false);
						else if (suit[count6]==1||suit[count6]==2)
							AnsiPrint(cardstr,red,white, false, false);
					}
				}
				cout<<" ";
			}
			cout << endl;
		}
	}
	//
	return 0;
}
