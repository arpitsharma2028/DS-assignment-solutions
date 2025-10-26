#include <iostream>
using namespace std;
/*
2. Display all the node values in a circular linked list, repeating value of head node at the  end too.  
Input: 20 → 100 → 40 → 80 → 60,  
Output: 20 100 40 80 60 20. 
*/
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
        void insertionAtHead(int val)
    {
        Node *NewNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = NewNode;
            tail->next = head;
        }
        else
        {
            NewNode->next = head;
            head = NewNode;
            tail->next = head;
        }
        return;
    }
    void display(){
        if(head == NULL){
            cout<<"list is empty "<<endl;
            return;
        }
        Node* temp = head;
        cout<<temp->data<<" ";
        temp = temp->next;
        while (temp!= head)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
};
int main()
{
    CLL list;
    int arr[5] = {20 , 100 , 40 , 80 , 60};
    for(int i = 0 ; i < 5 ; i++)list.insertionAtHead(arr[i]);
    list.display();
}