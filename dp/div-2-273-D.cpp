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
    
    // dp[j] = ways to use exactly j red blocks for levels processed so far
    vector<ll> dp(r+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= h; i++){
        // Traverse in reverse to avoid overwriting values we still need
        for(int j = r; j >= 0; j--){
            // dp[j] already has "green for level i" case
            // Add "red for level i" case if possible
            if(j >= i){
                dp[j] = (dp[j] + dp[j-i]) % MOD;
            }
        }
    }

    ll totalBlocks = h * (h + 1) / 2;
    ll ans = 0;
    
    // Count valid configurations at height h
    for(int j = 0; j <= r; j++){
        ll greenUsed = totalBlocks - j;
        if(greenUsed >= 0 && greenUsed <= g){
            ans = (ans + dp[j]) % MOD;
        }
    }

    cout << ans;

    return 0;
}