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

class CLL {
public:
    Node* head;
    Node* tail;

    CLL() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;  
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;  
        }
    }

    void insertAfter(int val, int pos) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
            if (temp == head) {  
                cout << "Position out of range.\n";
                return;
            }
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail) tail = newNode;  
    }

    void insert_before(int val, int pos) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        // if inserting before head
        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == head) {
                cout << "Position out of range.\n";
                return;
            }
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
    }

    Node* searchNode(int val) {
        if (!head) return NULL;
        Node* temp = head;
        do {
            if (temp->data == val) return temp;
            temp = temp->next;
        } while (temp != head);
        return NULL;
    }

    void deleteNode(int val) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* toDelete = searchNode(val);
        if (!toDelete) {
            cout << "Node not found\n";
            return;
        }

        // Case 1: Only one node
        if (head == tail && head->data == val) {
            delete head;
            head = tail = NULL;
            return;
        }

        // Case 2: Deleting head
        if (toDelete == head) {
            head = head->next;
            tail->next = head;
            delete toDelete;
            return;
        }

        // Case 3: Deleting other nodes
        Node* prev = head;
        while (prev->next != toDelete) {
            prev = prev->next;
        }

        prev->next = toDelete->next;
        if (toDelete == tail) tail = prev;
        delete toDelete;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CLL list;
    for (int i = 0; i < 5; i++) list.push_back(i + 1);
    list.display(); // 1 2 3 4 5

    
    list.insertAfter(0, 1);
    list.display(); // 1 2 0 3 4 5

    // Insert 1 before 4th index node
    list.insert_before(1, 4);
    list.display(); // 1 2 0 3 1 4 5

    // Delete node 5 and 0
    list.deleteNode(5);
    list.deleteNode(0);
    list.display(); // 1 2 3 1 4

    // Search node
    Node* found = list.searchNode(3);
    if (found) cout << "Node found: " << found->data << endl;
    else cout << "Node not found\n";
    return 0;
}