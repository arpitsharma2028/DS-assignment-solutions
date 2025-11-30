#include <bits/stdc++.h>
using namespace std;
// Given an integer array, check if it contains any duplicates using hash set.
bool doesDuplicate(vector<int>nums){
    set<int>s;
    for(int i = 0 ; i < nums.size() ; i++){
        if(s.find(nums[i]) != s.end())return true;
        s.insert(nums[i]);
    }
    return false;
}
int main(){
    vector <int> nums =  {1, 2, 3, 1};
    if(doesDuplicate(nums))cout<<"Contains Duplicate \n";
    else cout<<"No duplicate found";
}