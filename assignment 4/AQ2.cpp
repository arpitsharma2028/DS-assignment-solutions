// Name - Arpit
// Roll no - 1024030969
// Question-2
#include <iostream>
using namespace std;
#include <vector>
/*
2)  Develop a menu driven program demonstrating the following operations on Circular Queues:
    enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
*/
class Queue{
    private:
    
    int *arr;
    int capacity;
    int currSize;
    int r , f; // f ,  f

    public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int [capacity];
        currSize = 0 ;
        r = -1;
        f = 0;
    }

    void push(int val){
        if(currSize == capacity){
            cout<<"queue is full"<<endl;
            return;
        }
        r = (r+1)%capacity;
        arr[r] = val;
        currSize++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        else{
            f = (f+1)%capacity;
            currSize--;
        }

    }
    bool isEmpty(){
        return currSize == 0;
    }
    bool isFull(){
        return currSize == capacity;
    }
    int peek(){
        return arr[f];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int count = currSize;
        int i = f;
        while (count--) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};
int main() {
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();

    q.pop();
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.push(40);
    q.push(50);
    q.push(60);  // works because it's circular
    q.display();

    return 0;
}
