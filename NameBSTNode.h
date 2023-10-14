#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

class NameBSTNode
{
private:

	NameBSTNode*	left;
	NameBSTNode*	right; //pointer of left and right
	string m_name;
	int m_age;
	string m_StartDate;
	string m_FinishDate;
	char m_Category; //node's value
	

public:
	NameBSTNode() 
	{
		left = nullptr;
		right = nullptr;
		m_age = 0;
	}
	NameBSTNode(string name, int age, string s_date, string f_date, char category)
	{
		m_name = name;
		m_age = age;
		m_StartDate = s_date;
		m_FinishDate = f_date;
		m_Category = category;
		left = nullptr;
		right = nullptr;
	}
	//constructor
	~NameBSTNode() {} //destructor

	NameBSTNode*	getLeft()			{ return left; }
	NameBSTNode*	getRight()			{ return right; }
	string getFinishDate() { return m_FinishDate; }
	string getName() { return m_name; }
	int getAge() { return m_age; }
	string getStartDate() { return m_StartDate; }
	char getCategory() { return m_Category; }
	//return the private value

	void setLeft(NameBSTNode* left)						{ this->left = left; }
	void setRight(NameBSTNode* right)					{ this->right = right; }
	void setName(string name) { this->m_name = name; }
	void setAge(int age) { this->m_age = age; }
	void setStartDate(string start) { this->m_StartDate= start; }
	void setFinishDate(string finish) { this->m_FinishDate = finish; }
	void setCategory(char cate) { this->m_Category = cate; }
	//set the private value
};