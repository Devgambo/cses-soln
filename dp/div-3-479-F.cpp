#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);

    //dp[i] : longest subseq ending at interger i
    map<ll,ll> dp;
    dp[0] = 0;
    ll endval = 0;
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        
        dp[a[i]] = max(dp[a[i]] , dp[a[i] - 1] + 1);

        if(dp[a[i]] > ans){
            ans = dp[a[i]];
            endval = a[i];
        }
    }

    cout << ans << endl;
    vector<ll> ansvec;
    for(int i=n-1; i>=0; i--){
        if(a[i] == endval){
            ansvec.push_back(i+1);
            endval--;
        }
    }

    reverse(ansvec.begin(), ansvec.end());
    for(int i:ansvec){
        cout <<i<<" ";
    }
    return 0;
}