
#include "header.h"



int main (int argc, char * const argv[]) {
    // insert code here...this is the main function, it creates a shuffled deck and begin the story
	srand(time(NULL));
	Deck deck1=Deck();
	deck1.shuffle();
	char ch='y';
	int money=100;
	int moneyevolve[100]={money};
	int moneycount=0;
	
	cout << "Welcome to BlackJack!\n";
	while ((ch=='y' || ch=='Y') && (money>0)) {
		Hand gnomehand=Hand();
	Hand omehand=Hand();


	gnomehand.takeacard(deck1);
	omehand.takeacard(deck1);
	gnomehand.takeacard(deck1);
	omehand.takeacard(deck1);

	cout << "You have $"<< money;
	cout << endl;
	int bet=money+10;
	while (bet>money) {
		cout << "Please input your bet as a multiple of 10: \n";
		cin >> bet;
	}

	
	
		
	money-=bet;
	cout << "Now you have $"<<money<<endl;	
	omehand.display(1);
	cout << "Your hand: ";
	gnomehand.display(2);
	int gnomesum,black=0;
	gnomesum=gnomehand.sumup();
		if (gnomesum==BLACKJACK) {
			black=1;
		}

		else{	
	cout << "Double down?y/n?\n";
	char d;
	cin >> d;
	if (d=='y' || d=='Y')
	{
		money-=bet;
		bet*=2;
		gnomehand.takeacard(deck1);
		gnomehand.displaynew();
		
	}
			else {
	

			
    cout << "hit me? y/n?\n";
	char c;
	cin >> c;
	while (c=='y' || c=='Y') {
			gnomehand.takeacard(deck1);
		gnomehand.displaynew();
		if (gnomehand.sumup()>=BLACKJACK) {
			c='n';
		}
		else
		{cin >>c;}
	}
			}
		}
		
	gnomesum=gnomehand.sumup();
		cout << "Your sum is :"<< gnomesum<<endl;
	if (black==1) {
		cout << "Congratulations! You have blackjack!\n";
	} else if (gnomesum>BLACKJACK) {
		cout << "Busted! ChouChou!\n";
	}
	cout << "Dealers full hand: ";
	omehand.display(2);

	int omesum,omeblack=0;
	omesum=omehand.sumup();
		if (omesum==BLACKJACK) {
			omeblack=1;
		}
else
{while (omesum<=16) {
		omehand.takeacard(deck1);
		omehand.displaynew();
		omesum=omehand.sumup();
	}
}
	cout << "Dealer's sum: "<< omesum<<endl;
	if (omeblack==1) {
		cout << "Dealer has blackjack!\n";
	} else if (omesum>BLACKJACK) {
		cout << "Dealer busted!\n";
	}

	if (black==1 && omeblack==1 ) {
		money+=bet;
		cout << "Both blackjack! Money back!\n";
	}
	else if (black==1)
	{
		money+=bet*5/2;
		cout << "Awesome! Blackjack money!\n";
	}
	else if (gnomesum<=BLACKJACK && omesum>BLACKJACK)
	{
		money+=bet*2;
		cout << "I win!\n";
	}
	else if (gnomesum<=BLACKJACK && gnomesum>omesum)
	{
		money+=bet*2;
		cout << "I win!\n";
	}
	
cout << "Now you have $"<< money<< endl;
		moneycount++;
		moneyevolve[moneycount]=money;
	cout << "Continue?y/n\n";

		cin >> ch;
		deck1.needtoshuffle();
	} 
	cout << "Thanks for playing! \n";
	for (int i=0; i<=moneycount; i++) {
		cout << moneyevolve[i]<<" ";
		
	}
	cout << endl;
return 0;
}




