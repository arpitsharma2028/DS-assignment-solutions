// assignment-1  question 5

/*
problem statement:
Write a program to find sum of every row and every column in a two-dimensional array.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> eachRowAndEachColSum(vector<vector<int>> mat){
    vector<vector<int>>ans;
    vector<int>Rsum;
    vector<int>Csum;
    for(int i = 0 ; i < mat.size() ; i++){// row wise sum;
        int sum = 0;
        for(int j = 0 ; j< mat[0].size() ; j++){
            sum+= mat[i][j];
        }
        Rsum.push_back(sum);
    }
    for(int i = 0 ; i < mat[0].size() ; i++){// column wise sum;
        int sum = 0;
        for(int j = 0 ; j < mat.size() ; j++){
            sum+= mat[j][i];
        }
        Csum.push_back(sum);
    }
    ans.push_back(Rsum);
    ans.push_back(Csum);
    return ans;
}
int main(){
    // test case : matrix = {{1,2,3} , {4,5,6} , {7,8,9}};
    vector<vector<int>>matrix = {{1,2,3} , {4,5,6} , {7,8,9}};
    vector<vector<int>>ans = eachRowAndEachColSum(matrix);
    for(int i = 0 ; i < matrix.size() ; i++){ // row sum
        cout<<"sum of "<<i<<" th row is "<<ans[0][i] <<endl;
    }

    for(int i = 0 ; i < matrix[0].size() ; i++){ // col sum
        cout<<"sum of "<<i<<" th col is "<<ans[1][i] <<endl;
    }
    return 0;
}


