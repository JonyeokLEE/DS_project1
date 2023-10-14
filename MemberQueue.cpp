#include "MemberQueue.h"

MemberQueue::MemberQueue()
{
    m_pHead = nullptr;
    m_pTail = nullptr;
    Queue_Size = 100;
    NumberOfElement = 0; //set variable
}

MemberQueue::~MemberQueue()
{

}

bool MemberQueue::empty() //Is this Queue empty?
{
    return NumberOfElement == 0;
}
bool MemberQueue::full() //Is this Queue full?
{
    return NumberOfElement == 100;
}
void MemberQueue::push(MemberQueueNode* node) //Push New Node
{
    if (empty()) //if empty
    {
        m_pHead = node;
        m_pTail = node;
        NumberOfElement++;
    }
    else if (full()) //Cannot push anymore
        exit(1);
    else //if is not empty
    {
        m_pTail->setNext(node);
        m_pTail = node;
        NumberOfElement++;
    }
}
MemberQueueNode* MemberQueue::pop() //POP
{
    if (empty()) //Cannot pop anymore
    {
        exit(1);
    }
    MemberQueueNode* currentNode = m_pHead; //to save head node
    m_pHead = m_pHead->getNext();
    NumberOfElement--;
    return currentNode; //return popped Node
}



MemberQueueNode* MemberQueue::front() //return the head node
{
    return m_pHead;
}

void MemberQueue::print(ofstream& write)
{
    MemberQueueNode* temp = m_pHead;
    write << "===== " << "LOAD" << " =====" << endl;
    while (temp)
    {
        write << temp->getName() << "/" << temp->getAge() << "/" << temp->getDate() << "/" << temp->getCategory() << endl;
        temp = temp->getNext();
    }
    write << "===============" << endl << endl;
}
