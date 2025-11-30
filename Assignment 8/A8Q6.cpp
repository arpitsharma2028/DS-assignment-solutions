// Implement priority queues using heaps.
#include <iostream>
#include <vector>
using namespace std;

class PriorityQueueHeap {

    vector<int> heap;

    void heapify(int parentIdx) {
        int largest = parentIdx;
        int left = 2 * parentIdx + 1;
        int right = 2 * parentIdx + 2;

        if(left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if(right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if(largest != parentIdx){
            swap(heap[parentIdx], heap[largest]);
            heapify(largest);
        }
    }

public:

    void push(int val){
        heap.push_back(val);

        int child = heap.size() - 1;
        int parent = (child - 1) / 2;

        while(child > 0 && heap[child] > heap[parent]){
            swap(heap[child], heap[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
    }

    void pop(){
        if(heap.empty()) return;

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(0);
    }

    int top(){
        if(heap.empty()) return -1;
        return heap[0];
    }

    bool isEmpty(){
        return heap.empty();
    }

    void print(){
        for(int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main(){

    PriorityQueueHeap pq;

    pq.push(40);
    pq.push(10);
    pq.push(50);
    pq.push(30);

    cout << pq.top() << endl;
    pq.print();

    while(!pq.isEmpty()){
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
