#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

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

int sizeOfLinkedList(Node *&head)
{
    if (head == NULL)
        return 0;

    Node *temp = head;

    int ctr = 0;
    while (temp != NULL)
    {
        ctr++;
        temp = temp->next;
    }

    return ctr;
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
Node *getNodeAt(Node *&head, int idx)
{
    Node *temp = head;
    for (int i = 0; i < idx; i++)
    {
        temp = temp->next;
    }
    return temp;
}

void deleteAtIndex(Node *&head, int idx)
{
    if (head == NULL)
        return;
    if (idx == 0)
    {
        Node *todelete = head;
        head = head->next;

        delete todelete;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        temp = temp->next;
    }

    Node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
    return;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);

    insertAtHead(head, 11);

    // <----- DELETE NODE AT GIVEN INDEX IN LINKEDLIST  ----->

    // TIME COMPLEXITY :- O(INDEX)

    display(head);

    deleteAtIndex(head, 5);
    deleteAtIndex(head, 0);
    deleteAtIndex(head, 0);
    deleteAtIndex(head, 3);
    display(head);
}
