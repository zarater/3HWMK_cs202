#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;


int main()
{
	int user = 0;
	int num = 0;
	int i = 0;
	char stop;
	char a_topic[100];
	char a_question[100];
	char chosenfile[100];
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
	ifstream file_in;

	file_in.open(chosenfile);
	if(!file_in) 
	{	cout << "error loading txt file" << endl; return 0;}

	while(!file_in.eof())
	{
		file_in.get(a_topic, 100, '#'); file_in.ignore();
		while(file_in.get(stop))
		{
		file_in.get(a_question, 100, ':'); file_in.ignore();
		cout << "a_question: "  <<  a_question << endl;
		}
		++i;//count questions but not needed
		cout << "a_topic: " << a_topic << endl;
	}

	cout << "do you want to continue? press 0 to stop" << endl;
	cin >> num; 
	if(num == 0)
	{ file_in.close();	return 0;}
	main();
	return 0;
}
