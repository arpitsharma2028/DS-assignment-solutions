#include <iostream>
using namespace std;
#include <vector>
#include <stack>
/*
3. Write a program that checks if an expression has balanced parentheses.
*/
bool isValid(string str) {
        stack<char>s;
    for(char ch : str){
        if(ch == '(' || ch =='{' || ch == '[')s.push(ch);
        else{ // why this else is used? -> dry run on ()
        if(s.empty()) return false;
        char top = s.top();
        if ((top == '{' && ch == '}') ||
            (top == '[' && ch == ']') ||
            (top == '(' && ch == ')'))s.pop();
        else return false;
        }
    }
    return s.empty();
    }
int main(){

}