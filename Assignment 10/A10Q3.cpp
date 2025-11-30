#include <bits/stdc++.h>
using namespace std;
// Count the frequency of each number in an array using a hash map.
void PrintFrequency(vector<int> &nums){
    unordered_map<int , int>m; // element , Frequency;
    for(int i = 0 ; i < nums.size() ; i++){
        m[nums[i]]++; // default value is 0;
    }
    for(auto a : m){
        cout<< "Frequency of " <<a.first <<" is "<<a.second<<endl;;
    }
}

int main(){

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "\n--- Frequency Count ---\n";
    
    PrintFrequency(nums);
    return 0;
}