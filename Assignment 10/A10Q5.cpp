/*
Given a linked list, determine whether it contains a loop (cycle) using a hash set.
A loop exists if some node’s next pointer points to a previous node in the list.
*/
#include <iostream>
#include <unordered_set>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

bool hasCycle(Node* head){
    unordered_set<Node*> visited;

    Node* temp = head;
    while(temp != NULL){
        if(visited.find(temp) != visited.end())
            return true; // loop found

        visited.insert(temp);
        temp = temp->next;
    }
    return false;
}

int main(){
    // Creating linked list: 1 → 2 → 3 → 4 → 2 (cycle at 2)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Create loop: last node points to node 2
    head->next->next->next->next = head->next;

    if(hasCycle(head))
        cout << "Cycle Found" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}
