/* Let's give it a try! You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 
*/
#include<bits/stdc++.h>
using namespace std;
 
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int x)
    {
        data=x;
        next=NULL;
    }

};
class MyStack
{
    StackNode *top;
    public:
        void push(int );
        int pop();
        MyStack()
        {
            top=NULL;
        }
    
};
void MyStack :: push(int x) 
{
    StackNode *curr=new StackNode(x);
    curr->next=top;
    top=curr;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if(top==NULL)
        return -1;
    int x=top->data;
    top=top->next;
    return x;
}