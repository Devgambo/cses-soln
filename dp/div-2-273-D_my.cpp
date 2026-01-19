#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll findh(ll r, ll g){
    ll h = 0;
    ll i = 1;
    while(h + i <= r+g){
        h+=i;
        i++;
    }
    return i-1;
}

int main(){
    ll r, g;
    cin >> r >> g;
    ll h = findh(r, g);
    
    // dp[i][j] = ways to color levels 1..i using exactly j red blocks
    vector<vector<ll>> dp(h+1, vector<ll>(r+1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= h; i++){
        for(int j = 0; j <= r; j++){
            // Option 1: level i is green
            dp[i][j] = dp[i-1][j];
            // Option 2: level i is red (need j >= i)
            if(j >= i){
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
    }

    ll totalBlocks = h * (h + 1) / 2;
    ll ans = 0;
    
    // Count valid configurations at height h
    for(int j = 0; j <= r; j++){
        ll greenUsed = totalBlocks - j;
        if(greenUsed >= 0 && greenUsed <= g){
            ans = (ans + dp[h][j]) % MOD;
        }
    }

    cout << ans;

    return 0;
}