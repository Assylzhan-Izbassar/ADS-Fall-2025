#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {
        // int mid = (l + r) / 2;
        int mid = l + (r - l) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
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

    sort(arr.begin(), arr.end()); // very critical; 

    int targetIdx = binarySearch(arr, target);

    cout << targetIdx << endl;

    return 0;
}