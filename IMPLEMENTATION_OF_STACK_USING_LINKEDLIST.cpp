#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

           // <-------- STACK FUNCTIONS ------>

Node *top;
int isEmpty()
{
    return top == NULL;
}

void Pop()
{
    if (isEmpty())
    {
        cout << "STACK IS EMPTY" << endl;
        exit(1);
    }
    Node *todelete = top;
    top = top->next;

    delete todelete;
}
void Push(int val)
{
    Node *temp = new Node();

    if (!temp)
    {
        cout << "STACK OVERFLOW" << endl;
        return;
    }

    temp->data = val;
    temp->next = top;
    top = temp;
}

int Top()
{
    if (isEmpty())
    {
        cout << "STACK IS EMPTY" << endl;
        exit(1);
    }
    return top->data;
}

void printStack()
{
    if (top == NULL)
    {
        cout << "STACK IS EMPTY" << endl;
        return;
    }
    Node *temp = top;

    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
        {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    // <-----  IMPLEMENTATION OF STACK USING LINKEDLIST  ----->

    /* TIME COMPLEXITY :- PUSH -> O(1)
                          POP  -> O(1)
                          TOP  -> O(1)
   */

    Push(10);
    Push(20);
    Push(30);
    Push(40);

    printStack();

    Pop();
    Pop();
    Pop();

    if (isEmpty())
    {
        cout << "STACK IS EMPTY" << endl;
    }

    Pop();
    cout << Top() << endl;
}
