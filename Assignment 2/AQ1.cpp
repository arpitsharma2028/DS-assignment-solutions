#include <iostream>
using namespace std;
#include <vector>
/*
1) Implement the Binary search algorithm regarded as a fast search algorithm with
run-time complexity of Ο(log n) in comparison to the Linear Search.
*/
int BinarySearch(vector<int> &nums, int target){
    int st = 0 , end = nums.size()-1;
    while (st<=end)
    {
        int mid = st+(end-st)/2;
        if(nums[mid] == target)return mid;
        else if (nums[mid]> target)end = mid-1;
        else st = mid+1;
    }
    return -1;
}
int main(){
    vector<int>V = {1,2,3,4,6,7,9,12};
    cout<<BinarySearch(V,9)<<endl;
    cout<<BinarySearch(V,3);
}