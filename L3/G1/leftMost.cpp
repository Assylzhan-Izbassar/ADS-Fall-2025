#include <iostream>

using namespace std;

int lowerBinarySearch(vector<int>& arr, int target) {
    int l = 0;
    int r = arr.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (arr[r] != target) {
        return -1;
    }
    return r;
}

int upperBinarySearch(vector<int>& arr, int target) {
    int l = 0;
    int r = arr.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (mid == arr.size() - 1 && l == mid) { 
            break;
        }

        if (arr[mid] <= target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (l - 1 >= 0 && arr[l - 1] != target) {
        return -1;
    }
    return l - 1;
}


int main () {

    vector<int> arr;

    int n;
    cin >> n;

    int x;

    for (int i=0; i<n; ++i) {
        cin >> x;
        arr.push_back(x);
    }

    int target;
    cin >> target;

    cout << *lower_bound(arr.begin(), arr.end(), target) << endl;

    cout << lowerBinarySearch(arr, target) << endl;

    return 0;
}