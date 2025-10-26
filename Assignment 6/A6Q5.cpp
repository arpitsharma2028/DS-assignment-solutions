#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // for testing purpose
    void makeCircular() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head; 
    }
    bool isCircular() {
        if (head == NULL)
            return false;
        Node* temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    cout << "before making it circular"<<endl;
    cout << (list.isCircular() ? "Circular\n" : "Not Circular\n");    
    cout << "After making circular: "<<endl;
    list.makeCircular();
    cout << (list.isCircular() ? "Circular\n" : "Not Circular\n");
    return 0;
}
