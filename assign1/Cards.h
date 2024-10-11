/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Cards.h
   PURPOSE
     Bitmaps for the poker cards
   NOTES
     Sample solution
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

const int kNPip=13;
const int kNSuit=4;
const int kNCards=52;
const int kCardWidth=11;
const int kCardHeight=11;
int draw_cards(int cardnum);

/* 'x's are special characters that will be replaced in printing */
static char card[kNPip][kCardHeight][kCardWidth+1]={{
  "***********",
  "*1x       *",
  "*         *",
  "*         *",
  "*         *",
  "*    x    *",
  "*         *",
  "*         *",
  "*         *",
  "*        1*",
  "***********"
}, {
  "***********",
  "*2x       *",
  "*         *",
  "*    x    *",
  "*         *",
  "*         *",
  "*         *",
  "*    x    *",
  "*         *",
  "*        2*",
  "***********"
}, {
  "***********",
  "*3x       *",
  "*         *",
  "*    x    *",
  "*         *",
  "*    x    *",
  "*         *",
  "*    x    *",
  "*         *",
  "*        3*",
  "***********"
}, {
  "***********",
  "*4x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*         *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        4*",
  "***********"
}, {
  "***********",
  "*5x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*    x    *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        5*",
  "***********"
}, {
  "***********",
  "*6x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        6*",
  "***********"
}, {
  "***********",
  "*7x       *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*  x x x  *",
  "*         *",
  "*  x   x  *",
  "*         *",
  "*        7*",
  "***********"
}, {
  "***********",
  "*8x       *",
  "*         *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*         *",
  "*        8*",
  "***********"
}, {
  "***********",
  "*9x       *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*        9*",
  "***********"
}, {
  "***********",
  "*10x      *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*         *",
  "*  x   x  *",
  "*    x    *",
  "*  x   x  *",
  "*       10*",
  "***********"
}, {
  "***********",
  "*Jx       *",
  "*  xxxxx  *",
  "*     x   *",
  "*     x   *",
  "*     x   *",
  "*     x   *",
  "*  x  x   *",
  "*   xxx   *",
  "*        J*",
  "***********"
}, {
  "***********",
  "*Qx       *",
  "*   xxx   *",
  "*  x   x  *",
  "*  x   x  *",
  "*  x   x  *",
  "*  x  xx  *",
  "*   xxxx  *",
  "*       x *",
  "*        Q*",
  "***********"
}, {
  "***********",
  "*Kx       *",
  "*  x   xx *",
  "*  x  x   *",
  "*  x x    *",
  "*  xx     *",
  "*  x x    *",
  "*  x  x   *",
  "*  x   xx *",
  "*        K*",
  "***********"
}};

