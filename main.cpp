#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "inheritence.h"

using namespace std;


int main()
{


	char chosenfile[100];
	int num = 0;
	int user = 0;
		cout << "load questions.txt? press 1 for yes, else type file name" << endl;
	cin >> user; 
	if(user == 1)  
	{
		strcpy(chosenfile, "questions.txt");

	}
	else
	{
	cout << "please type a file" << endl;
	cin.get(chosenfile, 100, '\n');	cin.ignore(100, '\n');
	}

	cout << chosenfile << endl;


	bst quiz(chosenfile);
	quiz.gethead()->getdata()->numTitle();
	quiz.display();
	cout << "do you want to continue? press 0 to stop" << endl;
	cin >> num; 
	if(num == 0)
	{ return 0;}
	main();
	return 0;
}

