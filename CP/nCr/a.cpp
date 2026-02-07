#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7; // or any prime modulus

// Modular multiplication
ll mod_mul(ll a, ll b, ll m) {
    return ((a % m) * (b % m)) % m;
}

// Modular exponentiation
ll mod_pow(ll base, ll exp, ll m) {
    ll res = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1) res = mod_mul(res, base, m);
        base = mod_mul(base, base, m);
        exp >>= 1;
    }
    return res;
}

// Modular inverse using Fermat's little theorem (m must be prime)
ll mminvprime(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}

// Compute nCr using precomputed factorials and inverse factorials
ll combination1(ll n, ll r, ll m, vector<ll> &fact, vector<ll> &ifact) {
    if (r < 0 || r > n) return 0;
    return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], m), m);
}

void solve() {
    int n = 10;
    vector<ll> fact(n + 1), ifact(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mod_mul(fact[i - 1], i, MOD);
    }

    ifact[n] = mminvprime(fact[n], MOD);
    for (int i = n - 1; i >= 0; i--) {
        ifact[i] = mod_mul(ifact[i + 1], i + 1, MOD);
    }

    cout << combination1(8, 6, MOD, fact, ifact) << endl; // Output: 28
}

int main() {
    solve();
    return 0;
}


// mminvprime() works only if MOD is prime.

// Precomputation is O(n), each nCr query is O(1).

// This approach is standard for combinatorics problems in competitive programming.