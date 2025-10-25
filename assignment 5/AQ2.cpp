
#include <iostream>
using namespace std;

class Node{
    public:
    Node* next ;
    int val;
    Node(){
    }
    Node(int num){
        val = num;
        next = NULL;
    }
};
class SLL{
    public:
    Node* head;
    SLL(){
        head = NULL;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        Node*temp = head;
        if(head == NULL) {
            head = newNode;
            return;
        }
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display(){
        Node*temp = head;
        while(temp!= NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
        return;
    }
};
Node* KeyDeletion(Node* head, int key) {
    int count = 0;
    if (head == NULL) return NULL;

    // Delete occurrences at the head
    while (head != NULL && head->val == key) {
        count++;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->val == key) {
            count++;
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Number of occurrences are " << count << endl;
    return head;
}

int main(){
    SLL List;
    List.push_back(1);
    List.push_back(2);
    List.push_back(1);
    List.push_back(2);
    List.push_back(1);
    List.push_back(3);
    List.push_back(1);
    List.display();
    List.head = KeyDeletion(List.head , 1);
    List.display();
}