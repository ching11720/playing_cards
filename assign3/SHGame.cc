/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include "SHGame.h"
#include "SHPlayer.h"
#include "SHDealer.h"
#include <iostream>

using namespace std;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.

SHGame::SHGame(SHPlayer& shp, SHDealer& shd):player(shp),dealer(shd)
											 // : menu(sizeof(menuItems)/sizeof(char*), menuItems)
{

}


// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool
SHGame::oneRun()
{
	answer=menu->getAnswer();
	if(answer==QUIT)
		return false;
	else return true;
}


// play gmae
void
SHGame::play()
{
	if(answer==ONE_MORE)
	{   
		moreCard();
	}
	else if(answer==GIVE_UP)
	{   
		giveUp();
	}
	else if(answer==RESTART)
	{   
		restart();
	}
	//print
    player.showCards();
    dealer.showCards();
    menu->print();
}


// give the player and dealer one more card
// check if we can do that first.
// and judge who has win the round if the player have 5 cards
void
SHGame::moreCard()
{
	if(flag==true)
	{
		if(player.getNumCards()==4)
		{
			player.addCard(Card(dealer.giveCard()));
            dealer.addCard();

			dealer.openFirstCard();
			//{TIE, WIN, LOSE}//
			if(dealer.judge(player)==WIN)
			{
				scoreP+=5;
				scoreD-=5;
				cout<<"You win. Good job.(You have "<<scoreP<<" points, I Have "<<scoreD<<" points.)\n";
			}

			else if(dealer.judge(player)==LOSE)
			{
				scoreP-=5;
				scoreD+=5;
				cout<<"I win. Try again.(You have "<<scoreP<<" points, I Have "<<scoreD<<" points.)\n";
			}

			else if(dealer.judge(player)==TIE)
			{
				cout<<"(You have "<<scoreP<<" points, I Have "<<scoreD<<" points.)\n";
			}
			flag=false;
		}
		else if(player.getNumCards()<5)
		{
			player.addCard(Card(dealer.giveCard()));
			dealer.addCard();
		}
	}
	else cout<<"GAME OVER!"<<endl;
}


// give up this round,
// and you'll lose your credit
// the bet is equivalent to the number of card you keep
void
SHGame::giveUp()
{
	dealer.openFirstCard();
	if(flag==true)
	{
		scoreP-=betCredit*player.getNumCards();
		scoreD+=betCredit*player.getNumCards();
		cout<<"I win. Try again. (You have "<<scoreP<<" points, I Have "<<scoreD<<" points.)\n";
		flag=false;
	}
	else cout<<"GAME OVER!"<<endl;
}


// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void
SHGame::restart()
{
	if(flag==false)
	{
		if(scoreP>0 && scoreD>0)
		{
			dealer.start(player);
			dealer.shuffle();
			player.openFirstCard();
			for(int i=0;i<2;++i)
			{
				player.addCard(Card(dealer.giveCard()));
				dealer.addCard();
			}
			flag=true;
		}
		else if(scoreP<=0 || scoreD<=0)
		{
			dealer.openFirstCard();
			cout<<"Sorry. Game over. No loan here.\n";
		}
	}
	else cout<<"Game is not over yet. Choose 'give up' to end a game\n";
}
