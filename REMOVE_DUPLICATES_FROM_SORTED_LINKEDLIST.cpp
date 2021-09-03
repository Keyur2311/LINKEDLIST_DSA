#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void display(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "";
        if (temp->next != NULL)
        {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

Node *removeDuplicate(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *temp = new Node(head->data);
    int prev = head->data;
    head = head->next;

    while (head != NULL)
    {
        if (head->data != prev)
        {
            insertAtTail(temp, head->data);
            prev = head->data;
        }
        head = head->next;
    }

    return temp;
}
int main()
{
    Node *head = new Node(1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 10);
    insertAtTail(head, 10);
    insertAtTail(head, 10);
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 30);
    insertAtTail(head, 11);
    insertAtTail(head, 11);

    // <----- REMOVE DUPLICATES IN A SORTED LINKEDLIST  ----->

    // TIME COMPLEXITY :- O(N

    display(head);
    Node *temp = removeDuplicate(head);
    display(temp);
}

