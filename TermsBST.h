#pragma once
#include "TermsBSTNode.h"

class TermsBST
{
private:
	TermsBSTNode* root; //root pointer
	int count; //count the deleted (Date Delete)

public:
	TermsBST();
	TermsBST(TermsBSTNode* toinsert); //constructor
	~TermsBST(); //destructor

	TermsBSTNode* getRoot();
	int getcount();
	//to get private value

	void insertTermsBST(TermsBSTNode* node); //insert
	void printTermsBST(TermsBSTNode* node, ofstream& write); //print
	void deleteNameBST(string name, TermsBSTNode* cur, TermsBSTNode* pcur);
	//delete name
	void deleteDateBST(string date, TermsBSTNode* cur, TermsBSTNode* pcur);
	//delete date
	
};