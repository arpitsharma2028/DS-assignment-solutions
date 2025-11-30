/*
You are given a binary tree (not a binary search tree). Write a program to check if
the tree contains any duplicate node values using hash set.
Your task is to:
1. Return true (or print "Duplicates Found") if there exists at least one duplicate value.
2. Otherwise, return false (or print "No Duplicates").
*/
#include <iostream>
#include <unordered_set>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        left = right = NULL;
    }
};

bool checkDuplicate(TreeNode* root, unordered_set<int> &set){
    if(root == NULL) return false;

    // Check if value already exists
    if(set.find(root->data) != set.end())
        return true;

    set.insert(root->data);

    // Check in left and right subtrees
    return checkDuplicate(root->left, set) || checkDuplicate(root->right, set);
}

int main(){

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3); // duplicate

    unordered_set<int> set;

    if(checkDuplicate(root, set))
        cout << "Duplicates Found" << endl;
    else
        cout << "No Duplicates" << endl;

    return 0;
}
