#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

class MemberQueueNode
{
private:
	MemberQueueNode* m_Next; //to point next node
	string m_Name;
	int m_Age;
	string m_GetDate;
	char m_Category; //Node's Value

public:
	MemberQueueNode() //constructor
	{
		m_Next = nullptr;
		m_Age = 0;
		m_Category = 0;
	}
	MemberQueueNode(string name, int age, string date, char category) //constructor with value
	{
		m_Next = nullptr;
		m_Name = name;
		m_Age = age;
		m_GetDate = date;
		m_Category = category;
	}
	~MemberQueueNode() {} //destructor
	// G E T
	string getName(void)
	{
		return m_Name;
	}
	int getAge(void)
	{
		return m_Age;
	}
	MemberQueueNode* getNext(void)
	{
		return m_Next;
	}
	string getDate(void)
	{
		return m_GetDate;
	}
	char getCategory(void)
	{
		return m_Category;
	}
	// to get private value
	void setNext(MemberQueueNode* nextnode) //to set next node
	{
		m_Next = nextnode;
	}

};