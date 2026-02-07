#include <bits/stdc++.h>
using namespace std;

int maxZerosAfterFlip(int n, vector<int>& v) {
    int originalZeroCount = 0;

    vector<int> gain(n);
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) {
            gain[i] = -1;
            originalZeroCount++;
        } else {
            gain[i] = 1;
        }
    }

    // Apply Kadane’s algorithm to find maximum subarray sum in gain[]
    int maxGain = gain[0];
    int curr = gain[0];
    for (int i = 1; i < n; ++i) {
        curr = max(gain[i], curr + gain[i]);
        maxGain = max(maxGain, curr);
    }

    // If all are 0s, flipping any subarray reduces count, so force flip at least one element
    if (originalZeroCount == n) return n - 1;

    return originalZeroCount + maxGain;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << maxZerosAfterFlip(n, v) << endl;
    return 0;
}
