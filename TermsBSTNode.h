#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

class TermsBSTNode
{
private:

	TermsBSTNode*	left;
	TermsBSTNode*	right; //left / right pointer
	string m_name;
	int m_age;
	string m_StartDate;
	string m_FinishDate; //node's value

public:
	TermsBSTNode() 
	{
		left = nullptr;
		right = nullptr;
		m_age = 0;
	}
	TermsBSTNode(string name, int age, string s_date, string f_date)
	{
		m_name = name;
		m_age = age;
		m_StartDate = s_date;
		m_FinishDate = f_date;
		left = nullptr;
		right = nullptr;
	} //constructor
	~TermsBSTNode() {} //destructor

	TermsBSTNode*	getLeft()			{ return left; }
	TermsBSTNode*	getRight()			{ return right; }
	string getFinishDate() { return m_FinishDate; }
	string getName() { return m_name; }
	int getAge() { return m_age; }
	string getStartDate() { return m_StartDate; }
	//get private values

	void setLeft (TermsBSTNode* left)	{ this->left = left; }
	void setRight(TermsBSTNode* right)	{ this->right = right; }
	void setName(string name) { this->m_name = name; }
	void setAge(int age) { this->m_age = age; }
	void setStartDate(string start) { this->m_StartDate = start; }
	void setFinishDate(string finish) { this->m_FinishDate = finish; }
	//set private values
};