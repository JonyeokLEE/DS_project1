#include "TermsBST.h"


TermsBST::TermsBST() : root(nullptr) //constructor
{
	count = 0;
}
TermsBST::TermsBST(TermsBSTNode* toinsert) //constructor
{
	root = toinsert;
	count = 0;
}
TermsBST::~TermsBST() //destructor
{

}


TermsBSTNode* TermsBST::getRoot() //return root
{
	return root;
}

int TermsBST::getcount() //return count
{
	return this->count;
}

void TermsBST::insertTermsBST(TermsBSTNode* node) //insert
{
	if (root == nullptr) //empty
		root = node; //node is root

	else
	{
		TermsBSTNode* p = root, * pp = nullptr;

		while (p)
		{
			pp = p;
			if (node->getFinishDate() < p->getFinishDate())
			{
				p = p->getLeft();
			}
			else
			{
				p = p->getRight();
			}
		}
		if (node->getFinishDate() < pp->getFinishDate())
			pp->setLeft(node);
		else
			pp->setRight(node);
		//find the position and insert
	}
}

void TermsBST::printTermsBST(TermsBSTNode* node, ofstream& write)
{
	if (node == nullptr) //nothing to print
	{
		return;
	}
	//print with inorder
	printTermsBST(node->getLeft(),write);
	write << node->getName() << "/" << node->getAge() << "/" << node->getStartDate() << "/" << node->getFinishDate() << endl;
	printTermsBST(node->getRight(), write);
}

void TermsBST::deleteNameBST(string name, TermsBSTNode* cur, TermsBSTNode* pcur)
{
	TermsBSTNode* p = cur;
	TermsBSTNode* pp = pcur;

	if (p == nullptr) return; //not found
	deleteNameBST(name, p->getLeft(), p);
	deleteNameBST(name, p->getRight(), p); //recursive call
	if (p->getName() == name) //if find same name
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
			return;
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
			return;
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
			return;
		}
		//p has both children
		TermsBSTNode* pprev = p;
		TermsBSTNode* prev = p->getRight();
		TermsBSTNode* curr = p->getRight()->getLeft();

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
		if (pprev == p)
			pprev->setRight(prev->getRight());
		else
			pprev->setLeft(prev->getRight());
		delete prev;
		return;
	}
	
}

void TermsBST::deleteDateBST(string date, TermsBSTNode* cur, TermsBSTNode* pcur) //delete date
{
	TermsBSTNode* p = cur;
	TermsBSTNode* pp = pcur;

	if (p == nullptr) return; //not found
	
	deleteDateBST(date, p->getLeft(), p);
	deleteDateBST(date, p->getRight(), p); //recursive call
	if (p->getFinishDate() < date)
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
			this->count++;
			return;
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
			this->count++;
			return;
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
			this->count++;
			return;
		}
		//p has both children
		TermsBSTNode* pprev = p;
		TermsBSTNode* prev = p->getRight();
		TermsBSTNode* curr = p->getRight()->getLeft();

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
		if (pprev == p)
			pprev->setRight(prev->getRight());
		else
			pprev->setLeft(prev->getRight());
		delete prev;
		this->count++;
		return;
	}
}
