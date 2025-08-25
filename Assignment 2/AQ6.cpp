// Arpit
// 1024030969
// 2C72
// Question 5

#include <iostream>
using namespace std;
#include <vector>

/*
6) Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices
*/

vector<vector<int>> Transpose(vector<vector<int>> &mat){
    vector<vector<int>>ans;
    for(int i = 0 ; i < mat.size(); i++){
        for(int j = 0 ; j < mat[0].size() ; j++){
            if(mat[i][j] != 0){
                ans.push_back({j ,i, mat[i][j]});
            }
        }
    }
    return ans;
}
vector<vector<int>> addition(vector<vector<int>> &mat1 , vector<vector<int>>& mat2){
    int m = mat1.size(), n = mat1[0].size(); // no need to store size of other as addition is possible if size of both is not same
    vector<vector<int>>ans;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            int val1 = mat1[i][j] , val2 = mat2[i][j] ;
            if( val1!= 0 && val2 != 0) ans.push_back({i, j, (val1+val2)});
            else if(val1 != 0) ans.push_back({i, j, (val1)});
            else if(val2 != 0 )ans.push_back({i, j, (val2)});
        }
    }
    return ans;
}
vector<vector<int>> multiply (vector<vector<int>> &mat1 , vector<vector<int>>& mat2){
    if(mat1[0].size() != mat2.size())return {} ; // multiplication not possible
    vector<vector<int>>triplet1,triplet2;
    for(int i = 0 ; i < mat1.size() ; i++ ){
        for(int j = 0 ; j < mat1[0].size() ; j++){
            int val = mat1[i][j];
            if(val!= 0 )triplet1.push_back({i , j , val});
        }
    }
    for(int i = 0 ; i < mat2.size() ; i++ ){
        for(int j = 0 ; j < mat2[0].size() ; j++){
            int val = mat2[i][j];
            if(val!= 0 )triplet2.push_back({i , j , val});
        }
    }
    




    vector<vector<int>> ans;

    return ans;
}
int main(){

}
