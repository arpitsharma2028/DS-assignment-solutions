/*
Q3. Write a program for BST having functions for:
(a) Insert element (no duplicates allowed)
(b) Delete element
(c) Maximum depth of BST
(d) Minimum depth of BST
*/

#include <iostream>
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

Node* minNode(Node* root){
    while(root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL) return NULL;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else{
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;

        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root){
    if(root == NULL) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    Node* root = NULL;

    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);

    cout << "Inorder before delete: ";
    inorder(root);

    root = deleteNode(root, 30);

    cout << "\nInorder after delete: ";
    inorder(root);

    cout << "\nMax Depth: " << maxDepth(root);
    cout << "\nMin Depth: " << minDepth(root);

    return 0;
}
