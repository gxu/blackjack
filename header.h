/*
 *  header.h
 *  blackjack
 *
 *  Created by Dan on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

const int NUMBER=52;
const int BLACKJACK=21;
const int MAX=9;



class Deck
{
private:
	char deckofcards[NUMBER];
	int numberofcards;
	
public: 
	Deck();
	~Deck();
	void shuffle();
	char dealonecard();
	void display();
	void needtoshuffle();
};

class Hand  
{
private:
	char handofcards[MAX];
	int total;
	int cardnumber;
	void show(char x);
public:
	Hand();
	~Hand();
	int sumup();
	void takeacard(Deck & deck1);
	void display(int n);
	
	void displaynew();
	
};
#endif

