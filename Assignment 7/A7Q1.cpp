/*
1. Write a program to implement following sorting techniques:
a. Selection Sort
b. Insertion Sort
c. Bubble Sort
d. Merge Sort
e. Quick Sort
*/
#include <iostream>
using namespace std ;
#include <vector>
//a
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}
// b
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//c
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
//d
void merge(vector<int> &nums , int st , int end, int mid){
    int i = st , j = mid +1 ;
    vector <int> temp ;

    while (i<= mid && j<= end)
    {
        if(nums[i] <= nums[j] ){
            temp.push_back(nums[i++]);
        }
        else{
            temp.push_back(nums[j++]);
        }
    }

    // element left in left part
    while (i<=mid)
    {
        temp.push_back(nums[i++]);
    }
    // element left in right part
    while (j<= end)
    {
        temp.push_back(nums[j++]);
    }
    // element now place to original place in array
    for(int idx = 0 ; idx < temp.size() ; idx++ ){
        nums[st+idx] = temp[idx];
    }
    return;    
}
void MergeSort(vector<int> &nums , int st , int end){
    int mid = st + (end - st)/2 ;
    if(st == end) return ;

    if(st < end){
        MergeSort(nums , st , mid); // left inclusion
        MergeSort(nums , mid+1 , end); // right inclusion
        merge(nums , st , end , mid);
    }
}
int partition(vector<int> &nums , int st ,int end){
    int idx = st-1 , Piv = nums[end];
    int i  = st ;

    for(i = st ; i < end ; i++){ // i track whole array and idx track elements less than pivot
        if(nums[i]<= Piv){ // change sign if you want to sort in decreasinng order
            idx++ ;
            swap(nums[idx] ,nums[i] );
        }
    }
    idx++ ;
    swap(nums[idx] ,nums[end] );
    return idx;
}
//e
void quickSort(vector<int> &nums , int st ,int end){
    if(st== end)return;

    if(st<end){
        int PivIdx = partition(nums , st , end);
        quickSort(nums , st , PivIdx-1);
        
        quickSort(nums , PivIdx+1 , end);
    }
}
void printArray(vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}
int main(){
vector<int> nums = {3,5,7,2,6,1};

    selectionSort(nums);
    printArray(nums);
    nums = {3,5,7,2,6,1};
    insertionSort(nums);
    printArray(nums);

    nums = {3,5,7,2,6,1};
    bubbleSort(nums);
    printArray(nums);

    MergeSort(nums , 0 ,5 );
    printArray(nums);

    nums = {3,5,7,2,6,1};
    quickSort(nums , 0 , nums.size()-1);
    printArray(nums);
}
