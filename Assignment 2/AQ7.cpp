// Arpit
// 1024030969
// 2C71
// Question 7
// language used Cpp

#include <iostream>
using namespace std;
#include <vector>
int inversionCount(vector<int> &arr) {
    int n = arr.size(); 
    int invCount = 0; 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                invCount++;
        }
    }
    return invCount; 
}
int main() {
    vector<int> arr = {4, 3, 2, 1 , 5, 32, 3 };
    cout << inversionCount(arr) << endl; 
    return 0;
}