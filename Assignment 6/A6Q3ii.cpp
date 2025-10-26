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

    int  size(){
        if(head == NULL)return 0;
        else{
            int count = 0;
            Node* temp = head;
            do{
                count++;
                temp = temp->next;
            }
            while (temp!= head);
            return count;
        }
    }
};
int main()
{
    CLL list;
    int arr[5] = {20 , 100 , 40 , 80 , 60};
    for(int i = 0 ; i < 5 ; i++)list.insertionAtHead(arr[i]);
    list.display();
    cout<<"size of list is "<<list.size()<<endl;
}