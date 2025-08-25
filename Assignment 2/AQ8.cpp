// Arpit
// 1024030969
// 2C72

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <algorithm>
/*
problem statement:
Write a program to count the total number of distinct elements in an array of length n.
*/
int distinctElement(vector<int> &nums){ // brute force
    if(nums.size() == 0)return 0;
    sort(nums.begin() , nums.end());
    int temp = nums[0];
    int count = 1;
    for(int i = 1 ; i < nums.size() ; i++){
        if(nums[i] != nums[i-1])count++;
    }
    return count;
}
int uniqueEl(vector<int> &nums){// optimal solution wihtout sorting
    unordered_set<int>s;
    for(int i = 0 ; i < nums.size() ; i++)s.insert(nums[i]);
    return s.size();
}

int main(){
    vector<int> v = {4,3,7,6,73,7,4,2,4,5,7,3};
    cout<<distinctElement(v)<<endl;
    cout<<uniqueEl(v);
}