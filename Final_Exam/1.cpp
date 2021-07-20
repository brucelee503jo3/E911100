#include<iostream>
#include<cstdlib>
using namespace std;
struct ListNode
{
	ListNode *previousPtr;
	int data;
	ListNode *nextPtr;
};

ListNode **FirstPtr;

ListNode *getNewNode(int);
void InsertatFront(int);
void InsertatBack(int);

int main()
{
		
	
	return 0;	
} 
ListNode *getNewNode(int value )
{
	ListNode *newPtr = new (ListNode);
    if ( newPtr != NULL ) 
	{
    	newPtr->data = value;
    	newPtr->nextPtr = NULL;
    	newPtr->previousPtr = NULL;    	
    } 
	return newPtr;
}
void InsertatFront(int val)
{
	ListNode *newPtr=getNewNode(val);
	
	newPtr->nextPtr=(*FirstPtr);
	newPtr->previousPtr=NULL;
    (*FirstPtr)=newPtr;	 
}
void InsertatBack(int val)
{
    ListNode *newPtr=getNewNode(val);
    ListNode *prePtr,*currentPtr;  
      
    prePtr = NULL;
    currentPtr = *FirstPtr;

    while(currentPtr!=NULL) 
	{ 
        prePtr=currentPtr;     
        currentPtr=currentPtr->nextPtr;  
    }    
    prePtr->nextPtr = newPtr;
    newPtr->previousPtr = prePtr;  
} 
