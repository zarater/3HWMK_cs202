
class quizManager
{
	public:
		quizManager();
		quizManager(const quizManager&);
		~quizManager();
		int addquestion(char toadd_questions[]);
		int addtitle(char toadd_titles[]);
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


class bst
{
	public:
		bst();
		bst(char file_name[]);
		~bst();
		//int remove();
		//
		bst*& goleft();
		bst*& goright();
		l_node*& gethead();
		int remove(l_node* head);
		int file_extract(char chosenfile[]);
		
	protected:
		l_node* head;
		bst* right;
		bst* left;
};


