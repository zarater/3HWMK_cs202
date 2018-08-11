
class quizManager
{
	public:
		quizManager();
		quizManager(const quizManager&);
		~quizManager();
		int addquestion(char toadd_questions[]);
		int addtitle(char toadd_titles[]);
		int display();
		int numTitle();
	protected:
			char* title;
			char* question;
		
};
class trueandfalse: public quizManager
{
	public:
	protected:
};
class abcd: public quizManager	
{
	public:
	protected:
};

class l_node
{
	public:
		l_node();
		l_node(const l_node&);
		~l_node();
		l_node*& gonext();
		quizManager*& getdata();
		void getnext(l_node* newnext);

	protected:
		quizManager* data;
		l_node* next;
};

class d_node: public l_node
{
	public:
		d_node();
		d_node(const d_node&);
		~d_node();
};

class b_tree
{
	public:
	b_tree();
	~b_tree();
		b_tree*& goleft();
		b_tree*& goright();
		b_tree*& rightnext(b_tree* newnext);
		b_tree*& leftnext(b_tree* newnext);
		
		int initdata(int topic_name);
		int getdata();
	protected:
		b_tree* right;
		b_tree* left;
		int data;
};


class bst
{
	public:
		bst();
		bst(char file_name[]);
		~bst();
		//int remove();
		//
		l_node*& gethead();
		int remove(l_node* head);
		int file_extract(char chosenfile[]);
		int addbst();
		
	protected:
		l_node* head;
		b_tree* bhead;
};


