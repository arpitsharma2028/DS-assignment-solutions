#include <bits/stdc++.h>
using namespace std;
// Given two arrays, find the common elements using a hash set.
vector <int> CommonElement(vector<int>& nums , vector<int>&nums2){
    vector <int> ans;
    set<int>s;
    for(int i = 0 ; i < nums.size() ; i++){
        s.insert(nums[i]);
    }
    for(int i = 0 ; i < nums2.size() ; i++){
        if(s.find(nums2[i]) != s.end())ans.push_back(nums2[i]);
    }
    return ans;
}
int main(){
    vector<int>A = {1, 2, 3, 4 , 2};
    vector<int>B = {3, 4, 5, 6 , 2};
    vector<int>ans = CommonElement(A , B);
    for(int i : ans)cout<<i<<" ";
}