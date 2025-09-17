// Name - Arpit
// Roll no - 1024030969
// Question-3
#include <iostream>
using namespace std;
#include <queue>
/*
3)  Write a program interleave the first half of the queue with second half.
    Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
*/
void interLeaveQueue(queue<int> &Q){
    queue<int>temp;
    int n = Q.size();
    for(int i = 0 ; i < n/2 ; i++){
        temp.push(Q.front());
        Q.pop();
    }
    for(int i = 0 ; i < n/2 ; i++){
        Q.push(temp.front());
        temp.pop();
        Q.push(Q.front());
        Q.pop();
    }
}
int main()
{
    queue<int>Q;
    Q.push(4);
    Q.push(7);
    Q.push(11);
    Q.push(20);
    Q.push(5);
    Q.push(9);
    interLeaveQueue(Q);
    while (!Q.empty())
    {
        cout<<Q.front()<<"  ";
        Q.pop();
    }
    cout<<endl;
    
}