#include <iostream>
#include <vector>
using namespace std;

void improvedSelectionSort(vector<int>& arr)
{
    int start = 0, end = arr.size() - 1;

    while (start < end)
    {
        int minIndex = start;
        int maxIndex = start;

        // Find min and max in the current range
        for (int i = start; i <= end; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Bring minimum to the front
        swap(arr[start], arr[minIndex]);

        // If maximum was at start, update index after swap
        if (maxIndex == start)
            maxIndex = minIndex;

        // Bring maximum to the end
        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}
void display(vector<int>& arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr);

    cout << "\nSorted Array: ";
    display(arr);

    return 0;
}
