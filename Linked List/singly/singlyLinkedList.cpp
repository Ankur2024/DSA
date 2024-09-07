#include <iostream>
using namespace std;

class singlyLinkedList
{
    int data;
    singlyLinkedList *next;

public:
    singlyLinkedList() : data(0), next(nullptr) {}

    singlyLinkedList(int data, singlyLinkedList *next = nullptr) : data(data), next(next) {}

    void insertNode(int data);
    void deleteNode(int data);
    void printList();
};

singlyLinkedList *head = nullptr;

void singlyLinkedList::insertNode(int data) {
    singlyLinkedList *newNode = new singlyLinkedList(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    singlyLinkedList *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void singlyLinkedList::deleteNode(int value) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (head->data == value) {
        singlyLinkedList *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    singlyLinkedList *current = head;
    singlyLinkedList *prev = nullptr;

    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
}

void singlyLinkedList::printList() {
    singlyLinkedList *current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    singlyLinkedList node;

    node.insertNode(1);
    node.insertNode(2);
    node.insertNode(3);
    node.insertNode(4);

    cout << "List before deletion:" << endl;
    node.printList();

    node.deleteNode(3);

    cout << "List after deleting node with value 3:" << endl;
    node.printList();

    return 0;
}
