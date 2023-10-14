#include "Manager.h"

Manager::Manager()
{

}
Manager::~Manager()
{

}

void Manager::run(const char* command)
{
    fcmd.open(command); //open file to read
    flog.open("log.txt"); //open file to write
    if (!fcmd)
    {
        flog << "Fail to open command file" << endl;
        exit(-1);
    } //if fail to open command file

    string cmd; //string for read command file's line
    bool stop = false; //EXIT signal
    while (stop==false) //if stop == true -> EXIT
    {
        getline(fcmd, cmd); //get a line of command file
        if (cmd == ("LOAD")) //LOAD Command
        {
            bool success = LoadDataText(); //Run Load function
            if (success) //if success LOAD
            {
                queue.print(flog);
            }
            else
            {
                PrintErrorCode(100);
            }
        }
        else if (cmd.substr(0, 3) == ("ADD")) //ADD command
        {
            if (queue.full())
                exit(1);
            bool success = AddData(cmd.substr(4)); //Run Add Function
            if (!success) //if success ADD
            {
                PrintErrorCode(200);
            }
        }
        else if (cmd == ("QPOP")) //QPOP command
        {
            if (queue.empty())
                exit(1);
            bool success = QPOP(); //Run QPOP Function
            if (success) //if success QPOP
            {
                PrintSuccess("QPOP");
            }
            else
            {
                PrintErrorCode(300);
            }
        }
        else if (cmd.substr(0, 6) == ("SEARCH")) //SEARCH Command
        {
            string searchname = cmd.substr(7);
            bool success = namebst.searchNameBST(flog, searchname); //Run Search Functinon
            if (!success) //if fail to search
                PrintErrorCode(400);
        }
        else if (cmd.substr(0, 5) == ("PRINT")) //PRINT command
        {
            if ((cmd.length() > 7) && (cmd.substr(6, 4) == "NAME"))
            {   //if PRINT NAME
                if (namebst.getRoot() == nullptr) //if namebst is empty
                    PrintErrorCode(500);
                else
                {
                    namebst.printSet(namebst.getRoot(), flog); //Run NAME Print Function
                }
            }
            else if ((cmd.at(6) == 'A') || (cmd.at(6) == 'B') || (cmd.at(6) == 'C') || (cmd.at(6) == 'D'))
            {   //if PRINT Category
                char category = cmd.at(6); //get Category
                if (!PrintTerms(category)) //if there is no node with this category
                    PrintErrorCode(500);
            }
            else //Wrong Command set
            {
                PrintErrorCode(500);
            }
        }
        else if (cmd.substr(0, 6) == ("DELETE")) //DELETE command
        {
            if (cmd.substr(7, 4) == "NAME")
            {
                deleteName(cmd.substr(12)); //Run Delete Name
            }
            else if (cmd.substr(7, 4) == "DATE")
            {
                deleteDate(cmd.substr(12)); //Run Delete Date
            }
            else //Wrong Command
            {
                PrintErrorCode(600);
            }
        }
        else if (cmd == ("EXIT")) //EXIT command
        {
            PrintSuccess("EXIT");
            stop = true; //To Stop Loop
        }
        else //Wrong command
            PrintErrorCode(1000);
    }


    fcmd.close();
    flog.close(); //Close FIles
    return;
}

void Manager::PrintSuccess(const char* cmd) //Print Success
{
    flog << "===== " << cmd << " =====" << endl;
    flog << "Success" << endl;
    flog << "===============" << endl << endl;
}
void Manager::PrintErrorCode(int num) //Print Error Code
{
    flog << "===== ERROR =====" << endl;
    flog << num << endl;
    flog << "===============" << endl << endl;
}


bool Manager::LoadDataText() //Load data from "data.txt"
{
    ifstream readdata; //To read "data.txt"
    readdata.open("data.txt");
    if (!fread)
    {
        return false;
    }

    string line;
    while (getline(readdata, line))
    {
        vector<string> result; //to store the values into vector array
        stringstream ss(line);
        string temp;

        while (getline(ss, temp, ' ')) //seperate values on the basis of space
        {
            result.push_back(temp);
        }

        if (result.size() != 4) //if number of value is not 4
        {
            exit(1);
        }

        string name = result[0];
        int age = stoi(result[1]);
        string date = result[2];
        char category = result[3][0]; //store each values from vector

        MemberQueueNode* node = new MemberQueueNode(name, age, date, category); //create Node pointer
        queue.push(node); //push the node to queue
    }
    readdata.close(); //close the file
    return true; //Success Load
}

bool Manager::AddData(const string datatxt) //Add data from command
{
    //same with 'Load' Logic
    vector<string> result;
    stringstream ss(datatxt);
    string temp;

    while (getline(ss, temp, ' ')) //seperate on the basis of space and store to vector
    {
        result.push_back(temp);
    }

    if (result.size() != 4)
    {
        return false;
    }

    string name = result[0];
    int age = stoi(result[1]);
    string date = result[2];
    char category = result[3][0]; //store the values from vector

    MemberQueueNode* node = new MemberQueueNode(name, age, date, category);
    queue.push(node);
    flog << "===== " << "ADD" << " =====" << endl;
    flog << node->getName() << "/" << node->getAge() << "/" << node->getDate() << "/" << node->getCategory() << endl;
    flog << "===============" << endl << endl;
    return true;
}

bool Manager::QPOP() //QPOP function
{
    while (!queue.empty()) //until queue is empty
    {
        MemberQueueNode* popped = queue.pop(); //pop and get the popped node
        termslist.insertTermList(popped);
        namebst.insertNameBST(popped); //insert to each BST
    }
    return true;
}

void Manager::deleteName(string name) //Delete Name Function
{
    char category = namebst.searchCategory(name); //get Category
    if ((namebst.deleteNameBST(name))&& termslist.DeleteName(category, name)) //if both Delete functions are success
        PrintSuccess("DELETE");
    else
        PrintErrorCode(600);
}

void Manager::deleteDate(string date) //Delete Date Function
{
    if (namebst.deleteDateBST(date, namebst.getRoot(), 0) && termslist.DeleteDate(date)) //if both Delete functions are success
        PrintSuccess("Delete");
    else
        PrintErrorCode(600);
}

bool Manager::PrintTerms(char category) //Print TermsBST through TermsList
{
    TermsListNode* temp = termslist.SearchNode(category);
    if (!temp) //if there is no node with category what i want to print
        return false;
    if (!termslist.printTerms(category, flog, temp->getTree())) //if fail to print
        return false;
   
    return true; //if success to print
}




