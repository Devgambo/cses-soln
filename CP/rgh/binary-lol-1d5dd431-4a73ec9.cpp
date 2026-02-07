#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> getCoefficients(int k) {
    ll a = 1, b = 0;
    for (int i = 2; i < k; i++) {
        ll temp = b;
        b = a + b;
        a = temp;
    }
    return {a, b}; // f_k = a*f1 + b*f2
}

int solve(int n, int k) {
    if (k == 1 || k == 2) return (n >= 0 ? 1 : 0);

    int count = 0;
    auto [A, B] = getCoefficients(k);

    for (ll f1 = 0; A*f1 <= n; ++f1) {
        ll rem = n - A*f1;
        if (rem % B != 0) continue;

        ll f2 = rem / B;
        if (f2 >= f1) count++;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }

    return 0;
}
