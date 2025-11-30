#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Find the first non-repeating element in an array using a hash map.
int firstNonRepeating(vector<int> &nums){
    unordered_map<int,int> m;

    // Count frequencies , default value is 0;
    for(int num : nums)
        m[num]++;

    // Find first element with frequency = 1
    for(int num : nums){
        if(m[num] == 1)
            return num;
    }

    return -1;
}

int main(){
    vector<int> nums = {4, 5, 1, 2, 0, 4};

    int ans = firstNonRepeating(nums);

    cout << "First non-repeating element: " << ans << endl;

    return 0;
}
