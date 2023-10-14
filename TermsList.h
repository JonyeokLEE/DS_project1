#pragma once
#include "TermsListNode.h"
#include "TermsBST.h"
#include "MemberQueueNode.h"
#include <iostream>
using namespace std;

class TermsLIST
{
private:
	TermsListNode* head;
	TermsListNode* tail; //head and tail pointer
	int numA, numB, numC, numD;
	int length; //List's length
	//private member
	

public:
	TermsLIST(); //constructor
	~TermsLIST(); //destructor

	TermsListNode* getHead(); //to get head pointer

	void insertTermList(MemberQueueNode* Newone); //insert TermsListNode
	void SearchAndIncrease(char category); //search and increase num of node
	void SearchAndConnect(TermsBSTNode* newone, char category); //search and connect/insert to BST
	TermsBST* SearchBST(char category);
	TermsListNode* SearchNode(char category); //search and different return type
	string calculatefinaldate(string getstr, char category); //to get final date

	bool printTerms(char category, ofstream& write, TermsBST* bst); //print
	bool DeleteName(char category, string name); //delete
	bool DeleteDate(string date); //delete
};
