#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int l = 0;
    int r = arr.size();

    while (l < r) {
        int mid = (l + r) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            l = mid;
        } else {
            r = mid;
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