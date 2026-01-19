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
#define ed endl
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();
    int n;
    cin >> n;
    
    if(n<=9){
        cout << 1;
        return 0;
    }

    
    //dp[i] : min no of operations to form i;

    vector<int> dp(n+1, INT_MAX);
    
    for(int i=0 ; i<=9; i++){
        dp[i] = 1; 
    }

    for(int i=10; i<=n; i++){
        string s = to_string(i);
        for(char c: s){
            int dig = c - '0';
            if( i>=dig && dp[i-dig]!=INT_MAX){
                dp[i] = min(dp[i], dp[i-dig] + 1);
            }
        }
    }

    cout << dp[n];

    return 0;
}