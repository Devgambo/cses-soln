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
    string s , t;
    cin >> s >> t;
    
    int n = s.size();
    int m = t.size();

    // vector<vi> dp(n+1, vi(m+1,0));

    //base cases::
    // for(int i=0; i<n; i++)  dp[i][0] = i;
    // for(int j=0; j<m; j++)  dp[0][j] = j;
    
    vi curr(m+1);
    vi prev(m+1);
    for(int j=0; j<=m; j++)  prev[j] = j;
   
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j == 0){
                curr[0] = i;
                continue;
            }
            if(s[i-1]==t[j-1]){
                // dp[i][j] = dp[i-1][j-1];
                curr[j] = prev[j-1];
            }else{
                // int rep = 1 + dp[i-1][j-1];
                // int rem = 1 + dp[i][j-1];
                // int add = 1 + dp[i-1][j];
                // dp[i][j] = min({rem, add, rep});

                int rep = 1 + prev[j-1];
                int rem = 1 + curr[j-1];
                int add = 1 + prev[j];
                
                curr[j] = min({rem, add, rep});
            }
        }
        swap(curr, prev);
    }

    cout << prev[m];
    //sc  - O(2m)

    // cout << dp[n][m];
    // tc: O(n*m)
    // sc: O(n*m)


    return 0;
}