#include <iostream>

using namespace std;

void merge(vector<int>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);

    for (int i=0; i<n1; ++i) {
        L[i] = arr[l+i];
    }
    for (int j=0; j<n2; ++j){
        R[j] = arr[mid+j+1];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }

    while (j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }
}


void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r); 

        merge(arr, l, mid, r);
    }
}

int main()
{

    vector<int> arr = {3, -1, 2, 7, 5};

    mergeSort(arr, 0, arr.size()-1); 
    
    for (int i=0; i<arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}