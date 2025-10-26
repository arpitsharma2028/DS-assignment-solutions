#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char val) {
        data = val;
        next = prev = NULL;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = tail = NULL;
    }

    void insertAtEnd(char val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isPalindrome() {
        if (head == NULL || head->next == NULL)
            return true; // empty or single node list

        Node* left = head;
        Node* right = tail;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DLL list;
    string str;
    cout << "Enter a string: ";
    cin >> str;

    for (char ch : str)
        list.insertAtEnd(ch);

    cout << "Doubly Linked List: ";
    list.display();

    if (list.isPalindrome())
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is not a palindrome." << endl;

    return 0;
}
