#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
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

ll ipow(ll base, int exp) {
    ll result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}


ll f(ll n, ll k, ll ans, map<ll, ll> mp, vector<vector<int>> &dp){
    if(k<0 || n<0)
        return 1e15;
    if(n==0 && k >= 0)
        return ans;
    if(dp[n][k]!=-1)
        return dp[n][k];

    ll answer = 1e15;
    for(auto it:mp){
        answer = min(answer, f(n-it.first , k-1, ans + it.second , mp, dp));

    }
    return answer!=1e15?dp[n][k]=answer: answer;
}

int main() {
    fast_io();

    map<ll, ll> mp;
    for (int i = 0; i <= 20; i++) {
        ll key = ipow(3, i);
        ll value = ipow(3, i + 1);
        if (i > 0) value += i * ipow(3, i - 1);
        mp[key] = value;
    }

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n;
        cin >> k;
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        if(f(n,k,0,mp,dp) == 1e15)
            cout<<-1;
        else{
            cout<<f(n,k,0,mp,dp);
        }
        cout<<endl;
    }

    return 0;
}