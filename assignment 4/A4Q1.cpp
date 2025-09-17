// Name - Arpit
// Roll no - 1024030969
// Question-1
#include <iostream>
#include <vector>
using namespace std;
/*
1) Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
*/

class Queue {
    private:
    int capacity;
    int front , rear , *arr;
    public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int [capacity];
        front = 0;
        rear = -1;
    }
    void enqueue(int val){
        if(rear >= capacity-1){ 
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[++rear] = val;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        front++;
    }
    bool isEmpty(){
        return front > rear;
    }
    bool isFull(){
        return rear == capacity-1;
    }
    int peek(){
        return arr[front];
    }
    void display(){
        for(int i = front ; i <= rear ; i++ )cout<<arr[i]<<"    ";
        cout<<endl;
    }
};
int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.enqueue(60); // Overflow here
    q.display();
    while(!q.isEmpty())
    q.dequeue();

    q.dequeue(); // underflow
}
