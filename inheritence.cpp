#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "inheritence.h"

using namespace std;

/******************************/
bst :: bst(): head(NULL), right(NULL), left(NULL)
{}
bst :: bst(char file_name[])
{
	head = new l_node;

	file_extract(file_name);
}

bst :: ~bst()
{
	if(head) remove(head);
}

int bst :: file_extract(char chosenfile[])
{	
	int i = 0;
	char a_topic[100];
	char a_question[100];
	//quizManager* ptr = new trueandfalse;

	ifstream file_in;

	file_in.open(chosenfile);
	if(!file_in) 
	{	cout << "error loading txt file" << endl; return 0;}

	while(!file_in.eof())
	{
		file_in.get(a_topic, 100, '#'); file_in.ignore(100, '#');
		if(file_in.eof())
		{
			break;
		}
		while(file_in.peek()!='\n')
		{
		file_in.get(a_question, 100, ':'); file_in.ignore(100, ':');
		cout << "a_question: "  <<  a_question << endl;
		if(gethead() == NULL)
		{
		gethead()->getdata()->addquestion(a_question);//head->data = data
		gethead()->getnext(NULL);//head = head->next
		}
		else
		{
			l_node* temp = new l_node;
			temp->getdata()->addquestion(a_question);
			temp->getnext(head->gonext());
			head->getnext(temp);
			head = temp;
		}
		}

		file_in.ignore(100, '\n');
		cout << "a_topic: " << a_topic << endl;
		gethead()->getdata()->addtitle(a_topic);
		/****************************/
		//	b-tree set up 2-3 tree

		
		/*****************************/
		++i;//counts bst
	}
	file_in.close();
return 0;
}

bst*& bst :: goleft()
{
	return left;
}

bst*& bst :: goright()
{
	return right;
}


l_node*& bst :: gethead()
{
	return head;
}
int bst :: remove(l_node* head)
{

	if(!head) return 0;
	delete head;
	head->gonext();
	remove(head->gonext());
	head = NULL;
	return 0;
}
/******************************/

l_node::l_node(): data(NULL)
{}
l_node::l_node(const l_node&)
{}
l_node::~l_node()
{}
l_node*& l_node::gonext()
{
	return next;
}
quizManager*& l_node:: getdata()
{
	if(!data) data = new quizManager;
	return data;
}
void l_node:: getnext(l_node* newnext)
{
	next = newnext;
}

/******************************/
d_node :: d_node(){}
d_node ::	d_node(const d_node&){}
d_node ::~d_node(){}

/******************************/
quizManager :: quizManager(): title(NULL), question(NULL)
{}
quizManager ::	quizManager(const quizManager& source)
{
	title = new char[strlen(source.title)];
	strcpy(title, source.title);
	question = new char[strlen(source.question)];
}
quizManager ::	~quizManager()
{
	if(title) delete title;
	if(question) delete question;
}
int quizManager :: addquestion(char toadd_questions[])
{
	question = new char[strlen(toadd_questions)+1];
	strcpy(question, toadd_questions);
	return 1;
}
int quizManager :: addtitle(char toadd_titles[])
{
	title = new char[strlen(toadd_titles)+1];
	strcpy(title, toadd_titles);
	return 1;
}

/******************************/

