#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high - 1];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);

            cout << "swapped:\n";
            for (int i = 0; i < arr.size(); ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    swap(arr[i + 1], arr[high - 1]);

    cout << "last swapped:\n";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIdx = partition(arr, low, high);

        quickSort(arr, low, pivotIdx);
        quickSort(arr, pivotIdx + 1, high);
    }
}

int main()
{
    vector<int> arr = {5, 6, 3, 1, -1, -2};
    quickSort(arr, 0, arr.size());

    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}