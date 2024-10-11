/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <iostream>
#include <cstring>
#include <cassert>
#include "AnsiPrint.h"
#include "Card.h"
#include "CardPattern.h"
#include "SHPlayer.h"


using namespace std;

const char* HandTypeName[9] = {
    "Straight flush",
    "Four of a kind",
    "Full house",
    "Flush",
    "Straight",
    "Three of a kind",
    "Two pair",
    "One pair",
    "Other"
};

// constructor
SHPlayer::SHPlayer(const char* playerName)
{

}

// initialize the number of cards to 0
void
SHPlayer::start()
{
	cardNum=-1;
}

// add a new card to the current hand
// need to protect the array from overflowing
void SHPlayer::addCard(Card newCard)
{
	cardNum++;
	if(cardNum<kMaxCards)
    {   
        cards[cardNum]=newCard;
recheck:
        for(int i=0;i<cardNum;++i)
        {   
            if(cards[cardNum].getID()==cards[i].getID())
            {   
                cards[cardNum].setID(rand()%52);
                goto recheck;
            }   
        }
	}
}

// open the first card so it faces up
void
SHPlayer::openFirstCard()
{
	flag=true;
}

// print the current hand to the screen graphically
void
SHPlayer::showCards() const
{
	int count1,count2,count6;
	char cardstr[2];

	//from the first column to 11th//
    for(count1=0;count1<kCardHeight;++count1)
    {
        //from the 1st card to the 5th//
        for(count6=0;count6<kMaxCards;++count6)
        {
            for(count2=0;count2<kCardWidth;++count2)
            {
				if(flag==false&&count6==0)
				{
					sprintf(cardstr,"%c",card[13][count1][count2]);
					AnsiPrint(cardstr,white,white, false, false);
				}
				else
				{
                	if(card[cards[count6].getPip()][count1][count2]=='x')
                	{
                    	sprintf(cardstr,"%c",cardAbbrev[cards[count6].getSuit()]);
                    	if (cards[count6].getSuit()==0||cards[count6].getSuit()==3)
                        	AnsiPrint(cardstr,black,white, false, false);
                    	else if (cards[count6].getSuit()==1||cards[count6].getSuit()==2)
                        	AnsiPrint(cardstr,red,white, false, false);
                	}   
                	else
                	{
						sprintf(cardstr,"%c",card[cards[count6].getPip()][count1][count2]);
                	    if (cards[count6].getSuit()==0||cards[count6].getSuit()==3)
                    	    AnsiPrint(cardstr,black,white, false, false);
                    	else if (cards[count6].getSuit()==1||cards[count6].getSuit()==2)
                        	AnsiPrint(cardstr,red,white, false, false);
                	}
				}
            }
            cout<<" ";
        }
		cout<<endl;
	}
}

// get the total points of the current hand
int
SHPlayer::totalPips() const
{
	int point=0;
	int count7;
	for(count7=0;count7<kMaxCards;++count7)
		point+=cards[count7].getPip()+1;
	return point;
}

// judge what kind of hand type you own
// you need to have 5 cards
const char*
SHPlayer::getHandPattern() 
{
	sortCards();
	if(isStraightFlush()==true)
		return HandTypeName[0];
	else if(isFourOfAKind()==true)
		return HandTypeName[1];
	else if(isFullHouse()==true)
		return HandTypeName[2];
	else if(isFlush()==true)
		return HandTypeName[3];
	else if(isStraight()==true)
		return HandTypeName[4];
	else if(isThreeOfAKind()==true)
		return HandTypeName[5];
	else if(isTwoPair()==true)
		return HandTypeName[6];
	else if(isOnePair()==true)
		return HandTypeName[7];
	else return HandTypeName[8];
}

// return the number of cards at hand
int
SHPlayer::getNumCards() const
{
	return cardNum;
}

void
SHPlayer::sortCards() 
{
	int arr[5];
	for(int i=0;i<5;++i)
	{
		arr[i]=cards[i].getID();
	}
	for(int i=0;i<5;++i)
	{
		for(int j=i;j<5;++j)
		{
			if(arr[j]<arr[i])
			{
				arr[j]^=arr[i];
				arr[i]^=arr[j];
				arr[j]^=arr[i];
			}
		}
	}
	for(int i=0;i<5;++i)
		sortedCards[i].setID(arr[i]);
}

// any five card sequence of same suit
bool 
SHPlayer::isStraightFlush() const
{
	for(int i=1;i<kMaxCards;++i)
	{
		if(sortedCards[i].getPip() != sortedCards[i-1].getPip()+1 || 
				sortedCards[i].getSuit() != sortedCards[i-1].getSuit())
			return false;
	}

	return true;
}

// four cards of the same pip
bool 
SHPlayer::isFourOfAKind() const
{
    // O O O O X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() &&
            sortedCards[0].getPip() == sortedCards[2].getPip() )
        return true;
    // X O O O O
    if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() &&
            sortedCards[1].getPip() == sortedCards[3].getPip() )
        return true;

    return false;
}

// three of a kind combined with a pair
bool 
SHPlayer::isFullHouse() const
{
    // O O O X X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;
    // X X X O O
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;

    return false;
}

// five cards of the same suit
bool
SHPlayer::isFlush() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getSuit() != sortedCards[i+1].getSuit() )
            return false;

    return true;
}

// five cards in sequence
bool 
SHPlayer::isStraight() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getPip() + 1 != sortedCards[i+1].getPip() )
            return false;

    return true;
}

// three cards of the same pip
bool 
SHPlayer::isThreeOfAKind() const
{
    for( int i = 0; i < kMaxCards - 2; i++ )
        if( sortedCards[i].getPip() == sortedCards[i+1].getPip() &&
                sortedCards[i].getPip() == sortedCards[i+2].getPip() )
            return true;

    return false;
}

// two cards of one pip, two cards of another pip
bool 
SHPlayer::isTwoPair() const
{
    // O O @ @ X
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[2].getPip() == sortedCards[3].getPip() )
        return true;
    // O O X @ @
    if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;
    // X O O @ @
    if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
            sortedCards[3].getPip() == sortedCards[4].getPip() )
        return true;

    return false;
}

// two cards of one pip
bool 
SHPlayer::isOnePair() const
{
    for( int i = 0; i < kMaxCards - 1; i++ )
        if( sortedCards[i].getPip() == sortedCards[i+1].getPip() )
            return true;

    return false;
}


