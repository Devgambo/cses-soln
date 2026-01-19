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
    int n, x;
    cin >> n >> x;
    vi h(n), s(n);
    for(int i=0; i<n; i++)  cin >> h[i];
    for(int i=0; i<n; i++)  cin >> s[i];

    vector<vi> dp(x+1, vi(n+1,0));
    for(int i=0; i<n; i++){
        dp[0][i] = 0;
    }

    for(int pr = 1; pr <= x; pr++){
        for(int i=n-1; i>=0; i--){
            int npk = dp[pr][i+1] + 0;
            int pk = 0;
            if(pr>=h[i]){
                pk = dp[pr-h[i]][i+1] + s[i];
            }
            dp[pr][i] = max(pk,npk);
        }
    }

    cout << dp[x][0];

    return 0;
}