// Arpit
// 1024030969
// 2C72
// Question - 4
// language used - Cpp
#include <iostream>
using namespace std;
#include <vector>
/*
problem statement
4) String Related Programs
(a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string.
(c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase.
*/

// a 
char* StrConcat(char str1[] , char str2[]){

    /*
    easier way to implement same function:
    string ConcatStr(string s1 , string s2){
    return (s1+s2);
    }
    */
   
    int size1 = 0 , size2 = 0;

    while(str1[size1] != '\0'){
        size1++;
    }
    while(str2[size2] != '\0'){
        size2++;
    }
    char* ans = new char [(size1+size2+1)];
    int idx = 0; // track index of answer array;
    for(idx = 0 ; idx < size1 ; idx++){
        ans[idx] = str1[idx];
    }
    for(int i = 0 ; i < size2 ; i++){
        ans[idx] = str2[i];
        idx++;
    }
    ans[idx] = '\0';
    return ans;
}

// b
   void revStr(char * str){
        int n = 0;
        while (str[n] != '\0')n++;
        int i = 0 , j = n-1;
        while(i<=j)swap(str[i++],str[j--]);
        return;
    }
// c
    char* deleteVowels(char * str){ // assuming string contins only lowercase letters
        // calculate size and Vowels
        int size = 0 , vowels = 0; 
        while(str[size] != '\0'){
            if(str[size] == 'a' || str[size] == 'e' || str[size] == 'i' ||
                str[size] == 'o' || str[size] == 'u')vowels++ ;

            size++;
        }

        char* ans = new char [size-vowels+1]; // we have to add null character additionally at end
        int idx = 0;
        for(int i  = 0 ; i < size ; i++ ){
            if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i'
                &&str[i] != 'o' && str[i] != 'u')
            {
                    ans[idx] = str[i];
                    idx++;
            }
        }
        ans[idx] = '\0';
        return ans;
    }

    // d
    void SortString(char* str){
        int n = 0;
        while ( str[n] != '\0')
        {
            n++;
        }
        // try to use bubble sort here
        for(int i = 0 ; i < n-1 ; i++ ){
            bool isSorted = false;
            for(int j = 0 ; j < n-i-1 ; j++){
                if(str[j] > str[j+1]){
                swap(str[j] , str[j+1]);
                isSorted = true;
                }
            }
            if (!isSorted)break;
        }
        return;
    }
    // e
    void LowerToUpper(char * str){
        int i = 0 ; 
        while(str[i] != '\0'){
            if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A'); // convert
        } else {
            str[i] = str[i]; // copy unchanged
        }
        i++;
        } 
    }


int main(){
    char S1[] = "abc";
    char S2[] = "def";
    char* S3 = StrConcat(S1 , S2);
    cout<< S3<<endl; // abcdef

    revStr(S3);
    cout<<S3<<endl; // fedcba

    char* vowelLessWord = deleteVowels(S2);
    cout<<vowelLessWord<<endl; // df
    LowerToUpper(S3);
    cout<<S3<<endl; // FEDCBA
    SortString(S3);
    cout<<S3; //ABCDEF
}