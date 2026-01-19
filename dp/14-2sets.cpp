#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vc = vector<char>;
using vll = vector<ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define pb push_back
#define ff first
#define ss second

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();
    int n;
    cin >> n;

    ll ts = (1LL * n * (n + 1)) / 2;
    
    // If total sum is odd, can't split into two equal sets
    if(ts % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    
    ll target = ts / 2;

    vector<vll> dp(n + 1, vll(target + 1, 0));
    
    // Base case: one way to make sum 0 (pick nothing)
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    // dp[i][s] = number of ways to form sum s using elements 1 to i
    for(int i = 1; i <= n; i++){
        for(ll s = 1; s <= target; s++){
            dp[i][s] = dp[i-1][s];
            if(s >= i){
                dp[i][s] = (dp[i][s] + dp[i-1][s-i]) % MOD;
            }
        }
    }

    // Divide by 2 because each partition is counted twice
    // (choosing set A is same as choosing set B)
    ll ans = dp[n][target];
    
    // Modular division by 2: multiply by modular inverse of 2
    // Since MOD is prime, inverse of 2 = 2^(MOD-2) = (MOD+1)/2
    ll inv2 = (MOD + 1) / 2;
    ans = (ans * inv2) % MOD;
    
    cout << ans << endl;

    return 0;
}



