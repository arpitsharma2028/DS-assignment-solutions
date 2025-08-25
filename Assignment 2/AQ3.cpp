// Arpit
// 1024030969
// 2C72

#include <iostream>
using namespace std;
#include <vector>
/*
problem statement:
3) Design the Logic to Find a Missing Number in a Sorted Array. Given an array of n-1
distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array
(a) Linear time
(b) Using binary search 
*/
int missingElLinearSearch(vector<int> &nums){
    int ans = 0;
    for(int i = 1 ; i<= nums.size()+1 ; i++){
        ans = ans^i;
    }
    for(int i = 0 ; i < nums.size() ; i++)ans = ans^nums[i];
    return ans;
}
int missingElBinarySearch(vector<int> &nums){
    int st = 0 , end  = nums.size()-1;
    while (st<end)
    {
        int mid = st+(end-st)/2;

        if(nums[mid]>mid+1)end = mid;
        else st = mid+1;
    }
    return (nums[st] == st+1 )? st+2 : st+1;
}
int main(){
    
        vector<vector<int>> testCases = {
        {2,3,4,5},               // missing at beginning → 1
        {1,2,3,4},               // missing at end → 5
        {1,2,4,5,6},             // missing in middle → 3
        {1},                     // n=2 → missing = 2
        {2},                     // n=2 → missing = 1
        {1,2,3,5,6,7,8},         // random middle → 4
        {1,2,3,4,5,6,7,8,10}     // random middle → 9
    };
    cout<<"missing elements result using linear time complexity"<<endl;
    for(int i = 0 ; i < testCases.size() ; i++){
        cout<<"test case "<<i+1<<"  :" ;
        for(int j = 0 ; j < testCases[i].size() ; j++){
            cout<<" "<<testCases[i][j];
        }
        cout<<endl;
        // cout<<"missing element : "<<missingElBinarySearch(testCases[i])<<endl;
        cout<<"missing element : "<<missingElLinearSearch(testCases[i])<<endl;
    }
    cout<<"missing elements result using binary search : "<<endl<<endl;
    for(int i = 0 ; i < testCases.size() ; i++){
        cout<<"test case "<<i+1<<"  :" ;
        for(int j = 0 ; j < testCases[i].size() ; j++){
            cout<<" "<<testCases[i][j];
        }
        cout<<endl;
        // cout<<"missing element : "<<missingElBinarySearch(testCases[i])<<endl;
        cout<<"missing element : "<<missingElLinearSearch(testCases[i])<<endl;
    }
}