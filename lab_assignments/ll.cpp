#include <iostream>
#include "ll.h"
using namespace std;

Node::Node(int val)
{
    data = val;
}
Node::Node(int val, Node *n)
{
    data = val;
    next = n;
}
Node::Node() {}

SLL::SLL(){}

void SLL::push_back(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        { // if list is empty
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        { // traverse to last node
            temp = temp->next;
        }
        temp->next = newNode; // link new node at end
    }
