#include <vector>
#include <iostream>

using namespace std;

void soln() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    vector<pair<int, int>> ops;

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                ops.emplace_back(1, i + 1);
                changed = true;
            }
            if (b[i] > b[i + 1]) {
                swap(b[i], b[i + 1]);
                ops.emplace_back(2, i + 1);
                changed = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i]) {
            swap(a[i], b[i]);
            ops.emplace_back(3, i + 1);
        }
    }

    cout << ops.size() << '\n';
    for (auto [t, i] : ops) {
        cout << t << " " << i << '\n';
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        soln();
    }
    return 0;
}