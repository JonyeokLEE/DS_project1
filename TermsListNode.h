#pragma once
#include "TermsBST.h"
#include <string.h>
#include <string>
using namespace std;

class TermsListNode
{
private:

	TermsListNode*	next; //pointer of next node
	char category; //its category
	int NumOfMember; //Node's Num of Member
	TermsBST* ToTree; //pointer of BSTNode for each Node


public:
	TermsListNode() {
		next = nullptr;
		category = 0;
		NumOfMember = 0;
		ToTree = nullptr;
	} //constructor 
	TermsListNode(char cate) {
		next = nullptr;
		category = cate;
		NumOfMember++;
		ToTree = nullptr;
	} //constructor with value
	~TermsListNode() {} //destructor

	TermsListNode*	getNext()		 { return next; }
	TermsBST* getTree() { return ToTree; }
	int getNumofMem() { return NumOfMember; }
	char getCategory() { return this->category; }
	//to get private member

	void setNext(TermsListNode* next)	 { this->next = next; }
	void increaseNumOfMem() { NumOfMember++; }
	void decreaseNumOfMem(int num) { NumOfMember-= num; }
	void connectToTree(TermsBST* tree) { ToTree = tree; }
	//to set private member
};