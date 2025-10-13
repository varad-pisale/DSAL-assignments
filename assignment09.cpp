// Design a simplified railway reservation system where users can book,
// cancel, and view tickets. Use an array to store booking details and a
// queue to manage the waiting list.

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int ID;
    string issue;
    Queue *next = nullptr;

public:
    Queue() {}
    Queue(string isu)
    {
        issue = isu;
    }
    Queue(string isu, int id)
    {
        issue = isu;
        ID = id;
    }
    Queue(string isu, Queue *n)
    {
        issue = isu;
        next = n;
    }
    Queue(string isu, int id, Queue *n)
    {
        issue = isu;
        next = n;
        ID = id;
    }
    friend class Ticket_system;
};

class Ticket_system
{
    int identy = 1;
    Queue *front = nullptr, *rear = nullptr;

public:
    void add_ticket(string issue)
    {
        Queue *temp = new Queue(issue, identy++, front);
        if (rear == nullptr)
        {
            rear = temp;
            front = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    void urgent_ticket(string issue)
    {
        Queue *temp = new Queue(issue, identy++);
        if (front == nullptr)
        {
            rear = temp;
            front = temp;
        }
        else
        {
            rear->next=temp;
            temp->next = front;
            front = temp;
        }
    }
    void remove_ticket()
    {
        if (front == nullptr)
        {
            cout << "No tickets";
        }
        else
        {
            Queue *temp = front;
            front = front->next;
            delete temp;
        }
    }
    void print_all(Ticket_system st)
    {
        Queue *start = st.front;
        do
        {
            cout << start->ID << " " << start->issue << endl;
            start = start->next;
        } while (start != front);
    }
    void check_circular(Ticket_system ob)
    {
        cout << rear->next->ID << endl;
        cout << rear->next->issue << endl;
    }
};

int main()
{
    Ticket_system obj;
    cout << "Welcome to Complaint Ticketing system" << endl;
    cout << "1. Raise issue" << endl;
    cout << "2. Raise Urgent issue" << endl;
    cout << "3. Delete issue" << endl;
    cout << "4. Print all Tickets" << endl;
    cout << "5. Exit" << endl;
    cout << "6. Check circular" << endl;
    while (true)
    {
        int op;
        cout << "Enter Option: ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            string issue;
            cout << "Enter issue:";
            getchar();
            getline(cin, issue);
            obj.add_ticket(issue);
            break;
        }
        case 2:
        {
            string issue;
            cout << "Enter Urgent issue:";
            getchar();
            getline(cin, issue);
            obj.urgent_ticket(issue);
            break;
        }
        case 3:
            obj.remove_ticket();
            break;
        case 4:
            obj.print_all(obj);
            break;
        case 5:
            return 0;
        case 6:
            obj.check_circular(obj);
        default:
            cout << "Wrong option";
            break;
        }
    }

    return 0;
}