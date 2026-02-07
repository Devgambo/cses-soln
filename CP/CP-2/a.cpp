#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int x, int y) {

    const int MAX = 2 * max(a, b);
    vector<int> dist(MAX, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[a] = 0;
    pq.push({0, a});
    while (!pq.empty()) {

        auto [cost, curr] = pq.top();
        pq.pop();
        if (curr == b) return cost;

        if (curr + 1 < MAX && dist[curr + 1] > cost + x) {
            dist[curr + 1] = cost + x;
            pq.push({dist[curr + 1], curr + 1});
        }
        int xor_val = curr ^ 1;
        if (xor_val < MAX && dist[xor_val] > cost + y) {
            dist[xor_val] = cost + y;
            pq.push({dist[xor_val], xor_val});
        }
    }

    return -1;
}

int func() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    return f(a, b, x, y);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << func() << endl;
    }
    return 0;
}
