/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <iostream>
#include "SHPlayer.h"
#include "SHDealer.h"


// constructor
SHDealer::SHDealer()
{

}


// destructor
SHDealer::~SHDealer()
{

}


// distribute a card to the player
int
SHDealer::giveCard()
{
	givedCard++;
	return shuffleID[givedCard];
}


// give the dealer a card
void
SHDealer::addCard()
{
	givedCard++;
	dealer->addCard( Card( shuffleID[givedCard] ) );
}


// determind who has win the game.
// if both of them have the same pattern,
// the one has more total pips wins the game.
Result
SHDealer::judge(SHPlayer& player)
{
	if(dealer -> getHandPattern()>player.getHandPattern())
		return WIN;
	else if(player.getHandPattern()>dealer -> getHandPattern())
		return LOSE;
	else
	{
		if(dealer -> totalPips()>player.totalPips())
			return LOSE;
		else if(player.totalPips()>dealer->totalPips())
			return WIN;
		else return TIE;
	}
}


// start a new game(round)
// before starting a new game(round), you should have
// a new deck, and then shuffle it.
// The deck only has pips A, 8, 9, 10, J, Q, K.
void
SHDealer::start(SHPlayer& player)
{
	dealer->start();
	player.start();
	givedCard = -1;
	shuffleID=new int[28];
}


// shuffle the deck of cards
void
SHDealer::shuffle()
{
	int tmp=0,chosen;
	for(int i=0;i<4;++i)
	{
		shuffleID[i]=tmp;
		tmp++;
	}
	tmp=32;
	for(int i=4;i<24;++i)
	{
		shuffleID[i]=tmp;
		tmp++;
	}

	for(int i=0;i<24;++i)
	{
		chosen=rand()%24;
		tmp=shuffleID[i];
		shuffleID[i]=shuffleID[chosen];
		shuffleID[chosen]=tmp;
	}
}


// open the dealer's first card
void
SHDealer::openFirstCard()
{
	dealer->openFirstCard();
}


// show the dealer's hand to the screen
void
SHDealer::showCards() const
{
	dealer->showCards();
}
