// assignment-1 question 1

#include <iostream>
using namespace std;
#include <vector>
/*
problem statement :
1) Develop a Menu driven program to demonstrate the following operations of Arrays
——MENU——-
1. CREATE
2. DISPLAY
3. INSERT
4. DELETE
5. LINEAR SEARCH
6.EXIT

*/

// create
void ArrayCreation(vector<int> &nums , int n ){
    for(int i = 0 ; i < n ; i++){
        cout<<"Enter value for index"<<i<<endl;
        int val;
        cin>>val;
        nums.push_back(val);
    }
    return;
}
// display
void Display(vector<int>&nums){
    for(int i : nums){
        cout<< i<<"     ";
    }
    cout<<endl;
    return;
}
//INSERt
void Insertion(vector<int> &nums , int pos ,int val){
    int n = nums.size();
    nums.push_back(nums[n-1]);
    for(int i = n-1 ; i > pos  ; i--){
        nums[i] = nums[i-1];
    }
    nums[pos] = val;
    return ;
}

// deletion at ith index;
void Delete(vector<int> &nums , int idx){
    for(int i = idx ; i< nums.size() ; i++){
        nums[i] = nums[i+1];
    }
    nums.pop_back();
    return;
}

// linearSearch

int LinearSearch(vector <int> &nums , int target){
    for(int i = 0 ; i< nums.size() ; i++){
        if(nums[i] == target){
        return i;
        }
    }
    return -1; // target not available;
}

// EXIT
void exitProgram() {
    cout << "Exiting program...\n";
    exit(0);  // terminates the program
}

int main(){

vector<int> nums = {1,2,3,4,5}; // array creation
Insertion(nums , 1 , 10);
Display(nums); //  1     10     2     3     4     5   
Delete(nums , 2);
Display(nums); // 1     10     3     4     5   
cout<<"target is at "<< LinearSearch(nums , 5)<<" index."<<endl; // target is at 4th index.

exitProgram();
cout<< "code written here will not run because program terminated above ";

return 0;
}