/*
1. Develop a menu driven program for the following operations of on a Circular as well  as a Doubly Linked List. 
(a) Insertion anywhere in the linked list (As a first node, as a last node, and  after/before a specific node). 
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be  deleted may appear as a head node, last node or a node in between. 
(c) Search for a node. 
*/
#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        prev = next = NULL;
    }
};
class DLL{
    public:
    Node* head;
    Node* tail;
    DLL(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        if(head == NULL && tail ==NULL){
            Node *newNode = new Node(val);
            head = newNode;
            tail = newNode;
        }
        else{
            Node *newNode = new Node(val);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int val){
        if(head == NULL && tail ==NULL){
            Node *newNode = new Node(val);
            head = newNode;
            tail = newNode;
        }
        else{
            Node *newNode = new Node(val);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertAfter(int val , int pos){
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0 ; i < pos ; i++){
            temp = temp->next;
        } 
        if (temp == NULL) {
        cout << "Position out of range.\n";
        return;
        }

        if (temp == tail) { 
            push_back(val);
            return;
        }
        Node* next = temp->next;
        Node* newNode = new Node(val);
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = next;
        next->prev = newNode;
    }
    void insert_before(int val , int pos){
        insertAfter(val , pos-1);
    }
    void deleteNode(int val){
        if(!searchNode(val)){  // means if search function return NULL;
            return;
        }
        Node* toDelete = searchNode(val);

        if (toDelete == head) {
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL; 
        delete toDelete;
        return;
        }
        else if (toDelete == tail) {
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        delete toDelete;
        return;
        }

        Node* prev = toDelete->prev;
        Node* next = toDelete->next;
        prev->next = next;
        next->prev = prev;
        delete toDelete;
    }
    Node*  searchNode(int val){
        Node* temp = head;
        while(temp){
            if(temp->data == val)return temp;
            temp= temp->next;
        }
        cout<<"Node not found"<<endl;
        return NULL;
    }
    Node* display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    DLL list;
    for(int i = 0 ; i < 5 ; i++){
        list.push_back(i+1);
    }
    list.display();//  1 2 3 4 5 
    // insert 0 after 1th index node;
    list.insertAfter(0,1);
    list.display(); // 1 2 0 3 4 5 
    // insert 1 before 4th index;
    list.insert_before(1,4);
    list.display(); // 1 2 0 3 1 4 5 

    // delete node with value 5 and 0;
    list.deleteNode(5);
    list.deleteNode(0);
    list.display(); //  1 2 3 1 4 
}

