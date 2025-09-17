// Name - Arpit
// Roll no - 1024030969
// Question-4
#include <bits/stdc++.h>
using namespace std;
/*
Q-4 1st non repeating character in a string
*/
void IstNonRepeatingChar(string str){
    int freqArr[26] = {0};
    queue<char>Q;
    for(int i = 0 ; i < str.size() ; i++){
        char ch = str[i];
        Q.push(ch);
        freqArr[ch-'a']++;
        // we assume front of our queue to be non repating
        while (!Q.empty() &&freqArr[Q.front()-'a'] > 1 )
        {
            Q.pop();
        }
        if(Q.empty())cout<<-1<<"    ";
        else 
        cout<< Q.front()<<"     "; 
    }
}
int main(){
    string s = "aabc";
    IstNonRepeatingChar(s);
}