/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#ifndef _SHGAME_H_
#define _SHGAME_H_

#include "ConsoleMenu.h"

// forward declaration
class SHPlayer;
class SHDealer;

// menu for actions that are used in the show hand game
const char* const menuItems[] = {"One more card",
                                 "give up",
                                 "restart",
                                 "quit"
                                };

enum Option {ONE_MORE = 1, GIVE_UP, RESTART, QUIT};

// the show hand game
class SHGame {

	private:

		// menu item strings
		ConsoleMenu* menu=new ConsoleMenu(sizeof(menuItems)/sizeof(char*), menuItems);

		// references to a player and a dealer
		SHPlayer& player;
		SHDealer& dealer;

    public:

        /**
         * constructor
         * require an initialized player and a dealer
         */
        SHGame(SHPlayer& shp, SHDealer& shd);

        /**
         * one run of the game: return FALSE if quit
         * one run means taking and processing a user action
         */
        bool oneRun();

		void play();

	private:
        // routines to handles actions
        // give the each player one more card
        void moreCard();
        // give up this round
        void giveUp();
        // restart the game over
        void restart();

    private:

        // credits
        static const int initCredit = 20;
        static const int betCredit = 1;

        // TODO: more data and functions to add here ...
		
		int scoreP=initCredit,scoreD=initCredit;
		bool flag=true;
		int answer;
};


#endif // _SHGAME_H_
