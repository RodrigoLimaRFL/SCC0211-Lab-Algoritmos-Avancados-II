#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long int max_crossing_sum(const vector<int>& arr, int left, int mid, int right) {
    long long int left_sum = LLONG_MIN;
    long long int sum = 0;
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    long long int right_sum = LLONG_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

long long int max_subarray_sum(const vector<int>& arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int mid = left + (right - left) / 2;
    long long int left_max = max_subarray_sum(arr, left, mid);
    long long int right_max = max_subarray_sum(arr, mid + 1, right);
    long long int cross_max = max_crossing_sum(arr, left, mid, right);

    return max(left_max, max(right_max, cross_max));
}

int main() {
    int n;

    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << max_subarray_sum(arr, 0, n - 1) << endl;

    return 0;
}