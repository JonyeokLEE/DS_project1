#include "NameBST.h"

NameBST::NameBST() : root(nullptr) //constructor
{

}
NameBST::~NameBST() //destructor
{

}

NameBSTNode* NameBST::getRoot() //to get Root
{
	return root;
}

void NameBST::insertNameBST(MemberQueueNode* popped) //To insert NameBSTNode
{
	MemberQueueNode* temp = popped; //save popped queue node
	int age = temp->getAge();
	string name = temp->getName();
	string s_date = temp->getDate();
	char categ = temp->getCategory(); //set values from popped queue node

	string f_date = calculatefinaldate(s_date, categ); //calculate final date from start date and category

	NameBSTNode* newone = new NameBSTNode(name, age, s_date, f_date, categ); //create new node pointer
	insert_Name(newone); //start insert node
}

void NameBST::insert_Name(NameBSTNode* node)
{
	if (!root) //if there is no node in BST
	{
		root = node; //this node is root
		return;
	}

	NameBSTNode* p = root, * pp = nullptr; // p - current node and pp is parent of p
	while (p) //while p is not nullptr
	{
		pp = p; //update pp
		if (p->getName()> node->getName()) //if node's name is smaller than current's name
			p = p->getLeft(); //go to left
		else //if node's name is greater than / equal to current's name
			p = p->getRight(); //go to right
	}


	if (pp->getName() > node->getName()) //if pp's name is greater than node's name
		pp->setLeft(node); //pp's left is node
	else //else case
		pp->setRight(node); //pp's right is node
}

string NameBST::calculatefinaldate(string getstr, char category) //Calculate Final Date
{
	string date = getstr; //Start Date

	if (category == 'A') //+ 6 months
	{
		string month = date.substr(5, 2);
		int monthnum = stoi(month) + 6;
		if (monthnum > 12) //if month is greater than 12
		{
			monthnum -= 12;
			string fromint;
			if (monthnum < 10)
			{
				fromint = "0" + to_string(monthnum);
			}
			else
			{
				fromint = to_string(monthnum);
			}
			date.replace(5, 2, fromint);
			string year = date.substr(0, 4);
			int yearnum = stoi(year) + 1;
			fromint = to_string(yearnum);
			date.replace(0, 4, fromint);
			// Year + 1, Month + 6 - 12
		}
		else //if month is smaller than 12
		{
			string fromint;
			if (monthnum < 10)
			{
				fromint = "0" + to_string(monthnum);
			}
			else
			{
				fromint = to_string(monthnum);
			}
			date.replace(5, 2, fromint);
			//Just update the Date
		}
	}
	else if (category == 'B') //+ 12 months
	{
		string year = date.substr(0, 4);
		int yearnum = stoi(year) + 1;
		string fromint = to_string(yearnum);
		date.replace(0, 4, fromint);
		//Just update the Date
	}
	else if (category == 'C') //+ 24 months
	{
		string year = date.substr(0, 4);
		int yearnum = stoi(year) + 2;
		string fromint = to_string(yearnum);
		date.replace(0, 4, fromint);
		//Just update the Date
	}
	else if (category == 'D') //+ 36 months
	{
		string year = date.substr(0, 4);
		int yearnum = stoi(year) + 3;
		string fromint = to_string(yearnum);
		date.replace(0, 4, fromint);
		//Just update the Date
	}
	else //Wrong command
	{
		cout << "Error: Calculating final date\n";
		exit(1);
	}
	return date; //return the final date
}

void NameBST::printNameBST(NameBSTNode* node, ofstream& write) //print the node's value
{
	if (node == nullptr) //empty
	{
		return;
	}
	//inorder way
	printNameBST(node->getLeft(), write); //left
	write << node->getName() << "/" << node->getAge() << "/" << node->getStartDate() << "/" << node->getFinishDate() << endl;
	//current
	printNameBST(node->getRight(), write); //right
}

void NameBST::printSet(NameBSTNode* node, ofstream& write) //To print Node's Value with form
{
	write << "===== PRINT =====\nName_BST"<< endl;
	printNameBST(node, write);
	write << "===============" << endl << endl;
}

bool NameBST::searchNameBST(ofstream& write, string name) //To search Name
{
	NameBSTNode* p = root; //starting point
	while (p) //until p is not nullptr
	{
		if (name < p->getName())
		{
			p = p->getLeft();
		}
		else if (name > p->getName())
		{
			p = p->getRight();
		}
		else //if find the node
		{
			write << "===== SEARCH =====\n";
			write << p->getName() << "/" << p->getAge() << "/" << p->getStartDate() << "/" << p->getFinishDate() << endl;
			write << "===============" << endl << endl;
			//print and return true
			return true;
		}
		//the way to find node is similar with insert algorithm
	}
	if (p == nullptr) return false; //Cannot to find the node -> false
}

bool NameBST::deleteNameBST(string name) //Delete Name
{
	NameBSTNode* p = root; //starting point
	NameBSTNode* pp = nullptr; //parent of p
	while (p && p->getName() !=name) //until p is not nullptr AND p's name != name
	{
		pp = p;
		if (name < p->getName())
		{
			p = p->getLeft();
		}
		else if (name > p->getName())
		{
			p = p->getRight();
		}
		else
			break;
	} //search name complete
	if (p == nullptr) return false; //not found

	if (p->getLeft() == nullptr && p->getRight() == nullptr) //if p is leaf
	{
		if (pp == nullptr)
			root = nullptr;
		else if (pp->getLeft() == p)
			pp->setLeft(nullptr);
		else
			pp->setRight(nullptr);
		delete p;
		return true;
	}
	else if (p->getLeft() == nullptr) //if p has only right child
	{
		if (pp == nullptr)
			root = p->getRight();
		else if (pp->getLeft() == p)
			pp->setLeft(p->getRight());
		else
			pp->setRight(p->getRight());
		delete p;
		return true;
	}
	else if (p->getRight() == nullptr) //if p has only left child
	{
		if (pp == nullptr)
			root = p->getLeft();
		else if (pp->getLeft() == p)
			pp->setLeft(p->getLeft());
		else
			pp->setRight(p->getLeft());
		delete p;
		return true;
	}
	else //if p has both children
	{
		NameBSTNode* pprev = p;
		NameBSTNode* prev = p->getRight();
		NameBSTNode* curr = p->getRight()->getLeft();

		while (curr)
		{
			pprev = prev;
			prev = curr;
			curr = curr->getLeft();
		}
		p->setName(prev->getName());
		p->setCategory(prev->getCategory());
		p->setFinishDate(prev->getFinishDate());
		p->setStartDate(prev->getStartDate());
		p->setAge(prev->getAge());
		if (pprev == p)
			pprev->setRight(prev->getRight());
		else
			pprev->setLeft(prev->getRight());
		delete prev;
		return true;
	}
}

bool NameBST::deleteDateBST(string date, NameBSTNode* cur, NameBSTNode* pcur) //Delete Date
{
	NameBSTNode* p = cur;
	NameBSTNode* pp = pcur;

	if (p == nullptr) return false; //not found
	
	deleteDateBST(date, p->getLeft(), p);
	deleteDateBST(date, p->getRight(), p); //Recursive Call
	if (p->getFinishDate() < date) //if p's date is small than date -> delete
	{
		if (p->getLeft() == nullptr && p->getRight() == nullptr) //if p is leaf
		{
			if (pp == nullptr)
				root = nullptr;
			else if (pp->getLeft() == p)
				pp->setLeft(nullptr);
			else
				pp->setRight(nullptr);
			delete p;
			return true;
		}
		if (p->getLeft() == nullptr) //if p has only right child
		{
			if (pp == nullptr)
				root = p->getRight();
			else if (pp->getLeft() == p)
				pp->setLeft(p->getRight());
			else
				pp->setRight(p->getRight());
			delete p;
			return true;
		}
		if (p->getRight() == nullptr) //if p has only left child
		{
			if (pp == nullptr)
				root = p->getLeft();
			else if (pp->getLeft() == p)
				pp->setLeft(p->getLeft());
			else
				pp->setRight(p->getLeft());
			delete p;
			return true;
		}
		
		//p has both children
		NameBSTNode* pprev = p;
		NameBSTNode* prev = p->getRight();
		NameBSTNode* curr = p->getRight()->getLeft();

		while (curr)
		{
			pprev = prev;
			prev = curr;
			curr = curr->getLeft();
		}
		p->setName(prev->getName());
		p->setFinishDate(prev->getFinishDate());
		p->setStartDate(prev->getStartDate());
		p->setAge(prev->getAge());
		p->setCategory(prev->getCategory());
		if (pprev == p)
			pprev->setRight(prev->getRight());
		else
			pprev->setLeft(prev->getRight());
		delete prev;
		return true;
	}
}


char NameBST::searchCategory(string name) //search name's category
{
	NameBSTNode* p = root;
	while (p)
	{
		if (name < p->getName())
		{
			p = p->getLeft();
		}
		else if (name > p->getName())
		{
			p = p->getRight();
		}
		else
		{
			return p->getCategory();
		}
		//search node's name by comparing values
	}
	if (p == nullptr) return NULL; //Cannot find Node -> return NULL
}
