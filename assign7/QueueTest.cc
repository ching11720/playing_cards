/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     QueueTest.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Dec 11, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
}

#include <iostream>
#include <fstream>
#include "AnsiPrint.h"
#include "Queue.h"
#include "Except.h"

using namespace std;

/**
 * Print my id 
 */

void
PrintMyID(const char *studId) {

  char *str= new char[strlen(studId)+5];
  sprintf(str,"ID: %s",studId);
  AnsiPrint(str, yellow, red, true, true);
  cout << endl ;
  delete [] str;

}

/**
 * PrintUsage
 */

void
PrintUsage(const char *progName) {

    assert(progName);
    cout << "Usage: " << progName << " [passes [display [seed]]]" << endl;

}

int
main(int argc, char **argv) {

	istream *is1=&cin, *is2=&cin;

	if (argc>3) {
		PrintUsage(argv[0]);
		exit(-1);
	}
	else if (argc>2) {
		is2 = new ifstream(argv[2]);
		if (is2==NULL) {
			cerr << "Can't open file " << argv[2] << endl;
			exit(1);
		}
	} 
	if (argc>1) {
		is1 = new ifstream(argv[1]);
		if (is1==NULL) {
			cerr << "Can't open file " << argv[1] << endl;
			exit(2);
		}
	}

	// You need to provide testing exercises here

	// test integer queue
	Queue<int> *myIntQPtr=new Queue<int>;
	// enqueue exercises on myIntQPtr
	int da;
	while(*is1>>da)
		myIntQPtr->enqueue(da);
	// test copy constructor
	Queue<int> myIntQ = *myIntQPtr;
	// test destructor
	delete myIntQPtr;
	// dequeue exercises on myIntQ
	AnsiPrint("Integer Queue:", yellow, black, true, false);
	cout<<endl;
	myIntQ.dequeue();
	// test character queue
	Queue<char> myCharQ, myCharQ1;
	// enqueue exercises on myCharQ
	char ta;
	while(*is2>>ta)
		myCharQ.enqueue(ta);
	// test assignment operator
	myCharQ1=myCharQ;
	// dequeue exercise on myCharQ1
	AnsiPrint("Character Queue:", yellow, black, true, false);
	cout<<endl;
	myCharQ1.dequeue();
	// dequeue an empty queue to throw an exception
	Queue<int> mtQ;
	try{
		mtQ.dequeue();
		throw(Except("Attempt to dequeue empty queue"));
	}
	catch(Except &e)
	{
		AnsiPrint(e, red, yellow, true, false);
		cout<<endl;
	}
	
	PrintMyID("110703041");
	return 0;
}
