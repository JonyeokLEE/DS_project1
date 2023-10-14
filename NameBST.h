#pragma once
#include "NameBSTNode.h"
#include "MemberQueueNode.h"
using namespace std;

class NameBST
{
private:
	NameBSTNode* root; //BST's root node pointer
public:
	NameBST();
	~NameBST();

	NameBSTNode* getRoot(); //return the root

	// insert
	void insertNameBST(MemberQueueNode* popped); //get popped queue node
	void insert_Name(NameBSTNode* node); //insert
	string calculatefinaldate(string getstr, char category); //get final date
	void printNameBST(NameBSTNode* node, ofstream& write); //print with inorder
	void printSet(NameBSTNode* node, ofstream& write); //print set
	bool searchNameBST(ofstream& write, string name); //search node
	bool deleteNameBST(string name); //delete name
	bool deleteDateBST(string date, NameBSTNode* cur, NameBSTNode* pcur); //delete date

	char searchCategory(string name); //search category of name
	
};