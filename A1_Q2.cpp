
// assignment-1  question 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
problem statement
Design the logic to remove the duplicate elements from an Array and after the
deletion the array should contain the unique elements.
*/
vector<int> removeDuplicate(vector<int>&nums , vector<int>&ans){
    if(nums.empty() || nums.size() == 1)return ans = nums;
    sort(nums.begin() , nums.end());
    ans.push_back(nums[0]);
    for(int i = 1 ; i < nums.size() ; i++){
        if(nums[i] != nums[i-1])ans.push_back(nums[i]);
    }
    return ans;
}
int main(){
    vector<int>num = {1,1,2,3,3,6,7,9,9};
    vector<int>ans;
    removeDuplicate(num , ans);
    for(int i : ans)cout<<i<<"  ";
    cout<<endl;
}