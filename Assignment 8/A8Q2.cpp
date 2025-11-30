/*
Q2. Implement following functions for Binary Search Trees:

(a) Search a given item (Recursive & Non-Recursive)
(b) Maximum element of BST
(c) Minimum element of BST
(d) In-order successor of a given node in BST
(e) In-order predecessor of a given node in BST
*/

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* insertBST(Node* root, int val){
    if(root == NULL) return new Node(val);

    if(val < root->data) root->left = insertBST(root->left, val);
    else if(val > root->data) root->right = insertBST(root->right, val);

    return root;
}

bool searchRecursive(Node* root, int key){
    if(root == NULL) return false;
    if(root->data == key) return true;

    if(key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

bool searchIterative(Node* root, int key){
    while(root){
        if(root->data == key) return true;
        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

Node* minNode(Node* root){
    while(root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root){
    while(root->right) root = root->right;
    return root;
}

Node* successor(Node* root, int key){
    Node* ans = NULL;
    while(root){
        if(key < root->data){
            ans = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}

Node* predecessor(Node* root, int key){
    Node* ans = NULL;
    while(root){
        if(key > root->data){
            ans = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return ans;
}

int main(){

    Node* root = NULL;
    vector<int> arr = {20,10,5,15,30,25,40};

    for(int x : arr) root = insertBST(root, x);

    cout << "\nSearch (Recursive) 25 " 
         << (searchRecursive(root,25) ? "Found" : "Not Found");
    
    cout << "\nSearch (Iterative) 15 " 
         << (searchIterative(root,15) ? "Found" : "Not Found");

    cout << "\nMin Element : " << minNode(root)->data;
    cout << "\nMax Element : " << maxNode(root)->data;

    cout << "\nSuccessor of 20 : " << successor(root,20)->data;
    cout << "\nPredecessor of 20 : " << predecessor(root,20)->data;

    return 0;
}
