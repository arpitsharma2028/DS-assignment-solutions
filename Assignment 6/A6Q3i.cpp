#include <iostream>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};
class DoublyList{
    Node* head ;
    Node* tail;

    public :
    DoublyList(){
        head = tail = NULL ;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode ;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        return;
    }
    int size(){
        if(head == NULL)return 0;
        else{
            int count = 0;
            Node* temp = head;
            while(temp){
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    void PrintDLL(){
        Node* temp = head ;
        while(temp != NULL){
            cout<<temp->data<<" <-> ";
            temp = temp->next ;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    DoublyList list;
    int arr[5] = {20 , 100 , 40 , 80 , 60};
    for(int i = 0 ; i < 5 ; i++)list.push_back(arr[i]);
    list.PrintDLL();
    cout<<"size of list is "<<list.size()<<endl;
}