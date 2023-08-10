/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class MyLinkedList {
public:
    Node *head;
    MyLinkedList()
    {
       head=NULL;
    }

    int get(int index)
    {
        int count=0;
        Node *temp=head;
        while(count!=index && temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(temp==NULL)
            return -1;
        else
            return temp->data;
        
    }
    
    void addAtHead(int val)
    {
        Node *curr=new Node(val);
        if(head==NULL)
            head=curr;
        else
        {
            curr->next=head;
            head=curr;
        }
        
    }
    
    void addAtTail(int val) 
    {
        Node *curr=new Node(val);
        if(head==NULL)
            head=curr;
        else
        {
            Node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=curr;
        }
        
    }
    
    void addAtIndex(int index, int val)
    {
          Node *curr=new Node(val);
        if(index==0)
        {
            addAtHead(val);
            return;
        }
      
        Node *temp=head;
        int count=0;
        while(count!=index-1 && temp!=NULL)
        {
            count++;
            temp=temp->next;

        }
        if(temp==NULL)
            return ;
        curr->next=temp->next;
        temp->next=curr;
        
    }
    
    void deleteAtIndex(int index)
    {
        if(head==NULL)
            return ;
        int count=0;
        Node *temp=head;
        while(count!=index-1 && temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(index==0)
            head=head->next;
        if (temp == NULL || temp->next == NULL)
            return;
        temp->next=temp->next->next;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */