// Q4. Write a program to determine whether a given binary tree is a BST or not.
#include <iostream>
#include <climits>
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

bool isBST(Node* root, long minVal, long maxVal){
    if(root == NULL) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->right = new Node(12);  // breaks BST rule

    cout << (isBST(root, INT_MIN, INT_MAX) ? "Valid BST" : "Not a BST");

    return 0;
}
