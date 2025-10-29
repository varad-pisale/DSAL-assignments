#ifndef SLL_H // "if SLL_H is not defined"
#define SLL_H // define SLL_H

// class declarations

class Node
{
// private:  //try using private 
public:
    int data;
    Node *next = nullptr;

    friend class SLL;

    Node(int val);
    Node(int val, Node *n);
    Node();
};

class SLL
{
// private:
public:
    Node *head=nullptr;

    SLL();
    void push_back(int val);
    // void display();
};

#endif // end of include guard
