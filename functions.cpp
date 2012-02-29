/*
 *  functions.cpp
 *  blackjack
 *
 *  Created by Dan on 2/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "functions.h"
#include "header.h"

Deck::Deck()
{
	numberofcards=NUMBER;
	for (int i=0; i<NUMBER; i++) {
		for (int j=1; j<=13; j++) {
			switch (j) {
				case 1:
					for (int k=0; k<4; k++) {
						deckofcards[k]='A';
					}
					break;
				case 10:
				case 11:
				case 12:
				case 13:
					for (int k=0; k<4; k++) {
						deckofcards[(j-1)*4+k]=char(j);
					}
					break;
				default: 
					for (int k=0; k<4; k++) {
						deckofcards[(j-1)*4+k]=char(j);
					}
					break;
			}
			
		}
	}
	
}

Deck::~Deck()
{
}

void Deck::shuffle()
{
	int numofshuffle=NUMBER;
	char newdeck[NUMBER];
	char copyofdeck[NUMBER];
	for (int i=0; i<NUMBER; i++) {
		copyofdeck[i]=deckofcards[i];
	}
	
	for (int i=0; i<NUMBER ; i++) {
		int temp;
		temp=rand() % numofshuffle;
		newdeck[i]=copyofdeck[temp];
		for (int j=temp+1; j<numofshuffle; j++) {
			copyofdeck[j-1]=copyofdeck[j];
		}
		numofshuffle--;
		
	}
	for (int i=0; i<NUMBER; i++) {
		deckofcards[i]=newdeck[i];
	}
	numberofcards=NUMBER;
}
char Deck::dealonecard()
{
	int temp=numberofcards;
	numberofcards--;
	return deckofcards[temp-1];
	
}
void Deck::display()
{
	for (int i=0; i<numberofcards; i++) {
		
		switch (deckofcards[i]) {
			case 'A':
				cout << deckofcards[i];
				break;
			case char(11):
				cout << 'J';
				break;
			case char(12):
				cout << 'Q';
				break;
			case char(13):
				cout << 'K';
				break;
				
				
			default:cout << int(deckofcards[i]);
				break;
		}
		
		
	}
	cout << endl;
	
}

void Deck::needtoshuffle()
{
	if (numberofcards<NUMBER/2) {
		cout << "-----------Shuffling!!----------------\n";
		shuffle();
	}
}

Hand::Hand()
{
	for (int i=0; i<=MAX; i++) {
		handofcards[i]=char(0);
	}
	total=0;
	cardnumber=0;
	
}

Hand::~Hand()
{
}


void Hand::takeacard(Deck & deck1)
{
	handofcards[cardnumber]=deck1.dealonecard();
	cardnumber++;
}

void Hand::display(int n)
{
	char a=handofcards[0];
	char b=handofcards[1];
	switch (n) {
		case 1:
			cout << "Dealer hand: ";
			show(a);
			break;
		case 2:
			show(a);
			cout <<" ";
			show(b);
		default:
			break;
	}
	cout << endl;
}

void Hand::show(char x)
{
	if (x=='A') {
		cout << x;
	} else if (int(x)>1 && int(x)<11) {
		cout << int(x);
	} else {
		switch (x) {
			case 11:
				cout << 'J';
				break;
			case 12:
				cout << 'Q';
				break;
			case 13:
				cout << 'K';
				break;
			default:
				break;
		}
	}
	
}

void Hand::displaynew()
{
	show(handofcards[cardnumber-1]);
	cout << endl;
}

int Hand::sumup()
{
	int sum=0;
	int numberofa=0;
	for (int i=0; i<cardnumber; i++) {
		switch (handofcards[i]) {
			case 11:
			case 12:
			case 13:
				sum+=10;
				break;
			case 'A':
				sum+=11;
				numberofa++;
				break;
			default:
				sum+=int(handofcards[i]);
				break;
		}
	}
	if (numberofa!=0) 
		
	{while (sum>BLACKJACK && numberofa>0) {
		numberofa--;
		sum-=10;
	}
	}
	
	
	return sum;
}



