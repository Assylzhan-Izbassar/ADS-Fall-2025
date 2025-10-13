#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j=low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[high]);

    for (int k=0; k < arr.size(); ++k) {
        cout << arr[k] << " ";
    }
    cout << endl;
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);

        quickSort(arr, low, pivotIdx-1);
        quickSort(arr, pivotIdx+1, high);
    }
}

int main()
{
    vector<int> arr = {3, -1, 5, 30, 3, 65};

    quickSort(arr, 0, arr.size()-1); 
    
    for (int i=0; i<arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}