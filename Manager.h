#pragma once
#include "TermsList.h"
#include "MemberQueue.h"
#include "NameBST.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

class Manager
{
private:
	ifstream	fcmd; //object to read
	ofstream	flog; //object to write
	
	MemberQueue queue;
	NameBST namebst;
	TermsLIST termslist; //object of each Data Structure

public:
	Manager(); //constructor
	~Manager(); //destructor

	void run(const char* command); //run function
	
	//Print Set
	void PrintSuccess(const char* cmd);
	void PrintErrorCode(int num);

	//LOAD
	bool LoadDataText();
	//ADD
	bool AddData(const string datatxt);
	//QPOP
	bool QPOP();
	//DELETE
	void deleteName(string name);
	void deleteDate(string date);
	//PRINT (Terms)
	bool PrintTerms(char category);

};
