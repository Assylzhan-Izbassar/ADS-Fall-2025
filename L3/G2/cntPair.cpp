#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums;
    int n, x, target;

    cin >> n >> target;

    for (int i=0; i<n; ++i) cin >> x, nums.push_back(x);

    sort(nums.begin(), nums.end());

    int total_sum = 0;

    for (int i=0; i<nums.size(); ++i) {
        int num_i = nums[i];

        int l = i + 1;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (num_i + nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << "sub total pairs " << i << endl;
        cout << i << " " << r << endl;

        total_sum += (r - i);
    }

    cout << total_sum << endl;
    

    return 0;
}