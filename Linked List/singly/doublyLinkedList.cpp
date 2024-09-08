#include <bits/stdc++.h>
using namespace std;

class DoublyList
{
    int data;
    DoublyList *prev;
    DoublyList *next;

public:
    DoublyList(int data, DoublyList *next = nullptr, DoublyList *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    void insertAtBeginning(DoublyList *&head, int data)
    {
        DoublyList *newNode = new DoublyList(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(DoublyList *&head, int data)
    {
        DoublyList *newNode = new DoublyList(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        DoublyList *current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void printNode(DoublyList *head)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        DoublyList *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyList *head = nullptr;
    head->insertAtBeginning(head, 4);
    head->insertAtBeginning(head, 2);
    head->insertAtBeginning(head, 49);
    head->insertAtBeginning(head, 2);
    head->insertAtEnd(head,87);
    head->insertAtEnd(head,3);
    head->insertAtEnd(head,25);

    head->printNode(head);
    return 0;
}
