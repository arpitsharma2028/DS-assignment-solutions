#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int num) {
        val = num;
        next = NULL;
    }
};

class SLL {
public:
    Node* head;
    SLL() {
        head = NULL;
    }

    // (a) Insertion at beginning
    void push_front(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // (b) Insertion at end
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    // (c) Insertion before/after a specific value
    void insertBefore(int target, int val) {
        if (head == NULL) return;
        if (head->val == target) {
            push_front(val);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->val != target) temp = temp->next;
        if (temp->next == NULL) {
            cout << "Target value " << target << " not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp != NULL && temp->val != target) temp = temp->next;
        if (temp == NULL) {
            cout << "Target value " << target << " not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // (d) Deletion from beginning
    void pop_front() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) Deletion from end
    void pop_back() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    // (f) Deletion of a specific node (by value)
    void deleteValue(int value) {
        if (head == NULL) return;
        if (head->val == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->val != value) temp = temp->next;
        if (temp->next == NULL) {
            cout << "Value " << value << " not found!\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // (g) Search node and return position
    int search(int value) {
        Node* temp = head;
        int index = 0;
        while (temp != NULL) {
            if (temp->val == value) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    // (h) Display all nodes
    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty\n";
            return;
        }
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    SLL list;

    cout << "Insertion at beginning and end:\n";
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.display(); // 5->10->20->NULL

    cout << "\nInsertion after 10 (insert 15):\n";
    list.insertAfter(10, 15);
    list.display(); // 5->10->15->20->NULL

    cout << "\nInsertion before 10 (insert 7):\n";
    list.insertBefore(10, 7);
    list.display(); // 5->7->10->15->20->NULL

    cout << "\nDeletion from beginning:\n";
    list.pop_front();
    list.display(); // 7->10->15->20->NULL

    cout << "\nDeletion from end:\n";
    list.pop_back();
    list.display(); // 7->10->15->NULL

    cout << "\nDelete specific node (value 10):\n";
    list.deleteValue(10);
    list.display(); // 7->15->NULL

    cout << "\nSearch for value 15:\n";
    int pos = list.search(15);
    if (pos != -1)
        cout << "15 is at index " << pos << endl;
    else
        cout << "15 not found\n";

    return 0;
}
