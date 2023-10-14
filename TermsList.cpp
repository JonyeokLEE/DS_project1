#include "TermsList.h"

TermsLIST::TermsLIST(): head(nullptr)
{
	head = nullptr;
	numA = 0, numB = 0, numC = 0, numD = 0;
	length = 0;
}
TermsLIST::~TermsLIST()
{

}

TermsListNode* TermsLIST::getHead()
{
	return head;
}

void TermsLIST::insertTermList(MemberQueueNode* Newone)
{
	MemberQueueNode* temp = Newone; //get popped queue node

	char ListCategory = temp->getCategory();
	string name = temp->getName();
	string s_Date = temp->getDate();
	string f_Date = calculatefinaldate(s_Date, ListCategory);
	int age = temp->getAge();
	//store the values from popped queue node

	TermsBSTNode* newOne = new TermsBSTNode(name, age, s_Date, f_Date); //create new BSTNOde

	if (ListCategory == 'A') // A category
	{
		if (numA==0) //if A does not exist
		{
			TermsListNode* Toinsert = new TermsListNode(ListCategory);
			if (length == 0) //if list is empty
			{
				head = Toinsert;
				tail = Toinsert;
				length++;
			}
			else
			{
				tail->setNext(Toinsert);
				tail = Toinsert;
				length++;
			}
			//create new node and insert to list
			SearchAndConnect(newOne, ListCategory); //Connect to TermsBST
			numA++;
		}
		else //if the node is already exist
		{
			SearchAndIncrease(ListCategory);
			SearchAndConnect(newOne, ListCategory);
			//connect to TermsBST
			numA++;
		}
	}
	else if (ListCategory == 'B') //same logic with Category A example
	{
		if (numB == 0)
		{
			TermsListNode* Toinsert = new TermsListNode(ListCategory);
			if (length == 0)
			{
				head = Toinsert;
				tail = Toinsert;
				length++;
			}
			else
			{
				tail->setNext(Toinsert);
				tail = Toinsert;
				length++;
			}
			SearchAndConnect(newOne, ListCategory);
			numB++;
		}
		else
		{
			SearchAndIncrease(ListCategory);
			SearchAndConnect(newOne, ListCategory);
			numB++;

		}
	}
	else if (ListCategory == 'C') //same logic with Category A example
	{
		if (numC == 0)
		{
			TermsListNode* Toinsert = new TermsListNode(ListCategory);
			if (length == 0)
			{
				head = Toinsert;
				tail = Toinsert;
				length++;
			}
			else
			{
				tail->setNext(Toinsert);
				tail = Toinsert;
				length++;
			}
			SearchAndConnect(newOne, ListCategory);
			numC++;
		}
		else
		{
			SearchAndIncrease(ListCategory);
			SearchAndConnect(newOne, ListCategory);
			numC++;
		}
	}
	else if (ListCategory == 'D') //same logic with Category A example
	{
		if (numD == 0)
		{
			TermsListNode* Toinsert = new TermsListNode(ListCategory);
			if (length == 0)
			{
				head = Toinsert;
				tail = Toinsert;
				length++;
			}
			else
			{
				tail->setNext(Toinsert);
				tail = Toinsert;
				length++;
			}
			SearchAndConnect(newOne, ListCategory);
			numD++;
		}
		else
		{
			SearchAndIncrease(ListCategory);
			SearchAndConnect(newOne, ListCategory);
			numD++;
		}
	}
	else //Wrong Category or Node
	{
		cout << "Error to insert TermList" << endl;
		exit(1);
	}
}

void TermsLIST::SearchAndIncrease(char category) //search node by category and increase its element Num
{
	if (head == nullptr)
		return;
	TermsListNode* temp = head;
	while (temp->getCategory() != category && temp != nullptr) //search Node with category
	{
		temp = temp->getNext();
	}
	temp->increaseNumOfMem(); //increase
}

void TermsLIST::SearchAndConnect(TermsBSTNode* newone, char category) //search position and link TermsLISTNode and TemrsBST
{
	if (head == nullptr)
		return;
	TermsListNode* temp = head;
	while (temp->getCategory() != category && temp != nullptr) //search Node with category
	{
		temp = temp->getNext();
	}

	if (temp->getTree() == nullptr) //TermsBST does not exist -> create new one
	{
		TermsBST *pBST = new TermsBST;
		pBST->insertTermsBST(newone);
		temp->connectToTree(pBST); //insert to BST
	}
	else 
	{
		temp->getTree()->insertTermsBST(newone); //just insert to BST
	}
}


TermsBST* TermsLIST::SearchBST(char category) //Search with Category and return TermsBST*
{
	if (head == nullptr)
		return nullptr;
	TermsListNode* temp = head;
	while (temp != nullptr && temp->getCategory() != category)
	{
		temp = temp->getNext();
	}
	if (temp == nullptr) return nullptr;

	return temp->getTree();
}
// same logic about 'SEARCH'

TermsListNode* TermsLIST::SearchNode(char category) //Search with Category and return TermsListNode*
{
	if (head == nullptr)
		return nullptr;
	TermsListNode* temp = head;
	while (temp != nullptr && temp->getCategory() != category)
	{
		temp = temp->getNext();
	}
	if (temp == nullptr) return nullptr;
	
	return temp;
}

bool TermsLIST::printTerms(char category, ofstream& write, TermsBST* bst) //Print TermsBST
{
	if (bst->getRoot() == nullptr) //No connected BST -> false
		return false;
	write << "===== PRINT =====\nTerms_BST " << category << endl;
	bst->printTermsBST(bst->getRoot(), write); //Call PrintTermsBST function
	write << "===============" << endl << endl;
	return true;

}


bool TermsLIST::DeleteName(char category, string name) //delete name
{
	if (head == nullptr)
	{
		return false;
	}
	TermsListNode* temp = head;
	TermsListNode* prev = nullptr;
	while (temp->getCategory()!=category && temp!=nullptr)
	{
		prev = temp;
		temp = temp->getNext();
	} //find the List Node
	if (temp == nullptr) return false; //if there is no listnode -> false
	temp->getTree()->deleteNameBST(name, temp->getTree()->getRoot(), nullptr); //delete TermsBST about name

	temp->decreaseNumOfMem(1); //decrease Node's value
	if (temp->getNumofMem() == 0) //if there is no BST in list -> delete that list node
	{
		if (prev == nullptr)
		{
			head=temp->getNext();
		}
		else
		{
			prev->setNext(temp->getNext());
		}
		delete temp;
	}
	return true;
}

bool TermsLIST::DeleteDate(string date) //Delete Date
{
	if (head == nullptr)
	{
		return false;
	}
	TermsListNode* temp = head;
	TermsListNode* prev = nullptr;
	while (temp != nullptr)
	{
		temp->getTree()->deleteDateBST(date, temp->getTree()->getRoot(), 0); //delete date
		temp->decreaseNumOfMem(temp->getTree()->getcount()); //decrease Num of node
		temp = temp->getNext();
	}
	temp = head;
	prev = nullptr;
	while (!temp)
	{
		if (temp->getNumofMem() == 0) //if there is no BST in list -> delete that list node
		{
			prev = temp;
			if (temp->getTree()->getRoot() == 0)
			{
				if (prev == nullptr)
				{
					head = temp->getNext();
				}
				else
				{
					prev->setNext(temp->getNext());
				}
				TermsListNode* deleting = temp;
				temp = temp->getNext();
				delete deleting;
			}
			else
				temp = temp->getNext();
		}
	}
	return true;
}

string TermsLIST::calculatefinaldate(string getstr, char category) //Calculate Final Date
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
	else //wrong command
	{
		cout << "Error: Calculating final date\n";
		exit(1);
	}
	return date;
}
