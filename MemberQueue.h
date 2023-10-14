#pragma once
#include "MemberQueueNode.h"
#include "TermsList.h"
#include "NameBST.h"
using namespace std;



class MemberQueue
{
private:
	MemberQueueNode* m_pHead; //head pointer
	MemberQueueNode* m_pTail; //tail pointer
	int Queue_Size; //Queue Size
	int NumberOfElement; //Number of Queue element

public:
	MemberQueue();
	~MemberQueue();

	bool empty(); //empty or not
	bool full(); //full or not
	void push(MemberQueueNode* node); //push new node
	MemberQueueNode* pop(); //Queue Pop
	MemberQueueNode* front(); //get front node
	void print(ofstream& write); //print 
};

