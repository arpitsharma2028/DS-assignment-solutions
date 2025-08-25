// Arpit
// 1024030969
// 2C72

#include <iostream>
using namespace std;
#include <vector>
/*
problem statement:
2) Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping
the adjacent elements if they are in wrong order. Code the Bubble sort with the
following elements:
64 34 25 12  22 11 90
*/
void BubbleSort(vector <int> &nums){
    int n = nums.size();
    for(int i  = 0 ; i < nums.size()-1 ; i++){
        bool swapped = false;  // flag
        for(int j =0 ; j < n-i-1  ; j++){
            if(nums[j]>nums[j+1]){
            swap(nums[j+1], nums[j]);
            swapped = true;
            }
        }
        if(!swapped)break;
    }
}
int main(){
    vector<int>nums = {64 ,34, 25, 12, 22, 11, 90};
    BubbleSort(nums);
    for(int ch : nums)cout<<ch <<" ";
}
