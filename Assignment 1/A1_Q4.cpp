// assignment-1  question 4

/*
problem statement

Implement the logic to :
a. Reverse the elements of an array
b. Find the matrix multiplication
c. Find the Transpose of a Matrix
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// reverse element
vector<int> reverseArray(vector<int> &nums ){
    int i = 0 , j = nums.size()-1;
    while(i<=j){
        swap(nums[i++] , nums[j--]);
    }
    return nums;
}

// matrix multiplication
vector<vector<int>> MatMultiplication(vector<vector<int>>&mat1 ,vector<vector<int>>&mat2){
    if(mat1[0].size() != mat2.size()){
        cout<<" not possible to multiply these matrices"<<endl;
        return {{}};
    }
vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size(), 0));
// ans[i][j] = mat1[i][k]*mat2[k][j]

for(int i = 0 ; i < mat1.size() ; i++){
    for(int j = 0 ; j < mat2[0].size() ; j++){
        int val = 0;
        for(int k = 0 ; k < mat1[0].size() ; k++){
            val+= mat1[i][k] * mat2[k][j];
        }
        ans[i][j] = val;
    }
}
return  ans;
}

// transpose of matrice
vector<vector<int>> Transpose(vector<vector<int>>& mat){
     vector<vector<int>>ans(mat[0].size() , vector<int>(mat.size() , 0));
    for(int i = 0 ; i < mat.size() ; i++){
        for(int j = 0 ; j < mat[0].size() ; j++){
            ans[j][i] = mat[i][j];
        }
    }
    return ans;
}
int main() {
    // Reverse array test
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> rev = reverseArray(nums);
    cout << "Reversed array: ";
    for (int x : rev) cout << x << " ";
    cout << endl;

    // Matrix multiplication test
    vector<vector<int>> mat1 = {{1,2,3}, {4,5,6}};
    vector<vector<int>> mat2 = {{7,8}, {9,10}, {11,12}};
    vector<vector<int>> mul = MatMultiplication(mat1, mat2);
    cout << "Matrix Multiplication:\n";
    
    for (int i = 0 ; i < mul.size() ;i++) {
        for (int j = 0 ; j < mul[0].size() ; j++) {
            cout<<mul[i][j]<<"  ";
        }
        cout << endl;
    }

    // Transpose test
    vector<vector<int>> trans = Transpose(mat1);
    cout << "Transpose of mat1:\n";
    for (int i = 0 ; i < trans.size() ; i++) {
        for (int j = 0 ; j < trans[0].size() ; j++){
            cout<<trans[i][j]<<"    ";
        }
        cout << endl;
    }
    return 0;
}