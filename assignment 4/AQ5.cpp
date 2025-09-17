// Name - Arpit
// Roll no - 1024030969
// Question-5
#include <iostream>
#include <queue>
using namespace std;
/*
5)	Write a program to implement a stack using (a) Two queues and (b) One Queue.
*/
class stack{ // stack using 2 queues
    private:
    queue<int>Q1,Q2; // assume Q1 will act as stack
    public:
    void push(int x){
        while (!Q1.empty())
        {
            Q2.push(Q1.front());
            Q1.pop();
        }
        Q1.push(x);
        while (!Q2.empty())
        {
            Q1.push(Q2.front());
            Q2.pop();
        }
    }
    void pop(){
        if (Q1.empty()) {
        cout << "Already empty !"<<endl;
        return;
    }
        Q1.pop();
    }
    int top(){
        if(Q1.empty())return -1;
        return Q1.front();
    }
    bool isEmpty(){
        return Q1.empty();
    }
    void display(){
        while (!Q1.empty())
        {
            Q2.push(Q1.front());
            cout<<Q1.front()<<"    ";
            Q1.pop();
        }
        cout<<endl;
        while (!Q2.empty())
        {
            Q1.push(Q2.front());
            Q2.pop();
        }
    }
};
class stackk{ // stack using 1 queue
    private:
    queue<int>Q;
    public:
    // main focus is to push last element at 1st position else everything is sorted
    void push(int x){
        Q.push(x);
        for(int i = 1 ; i < Q.size() ; i++){
            Q.push(Q.front());
            Q.pop();
        }
        return;
    }
    void pop(){
         if (!Q.empty()) Q.pop();

    }
    int top(){
        return Q.front();
    }
    bool empty(){
        return Q.empty();
    }
};
int main(){
    stack S;
    for(int i = 0 ; i < 5 ; i++)
    S.push(i);
    S.display();
    S.pop();
    S.pop();
    S.display();
    cout<<S.top()<<endl;

    stackk S2;
    for(int i = 0 ; i < 5 ; i++)
    S2.push(i);
    S2.pop();
    while (!S2.empty())
    {
        cout<<S2.top()<<"   ";
        S2.pop();
    }
    cout<<endl;
}