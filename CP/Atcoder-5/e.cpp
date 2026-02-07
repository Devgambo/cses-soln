#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long ll;
const int MOD = 1e9+7;

#define SUVRAT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    SUVRAT

    ll n,q;
    cin >> n >> q;
    vector <ll> a(n);
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) a[i]--;
        

    vector<vector<ll>> lift(30,vector<ll>(n)), next(30,vector<ll>(n));
    for(ll i = 0; i < n; i++) 
    {
        lift[0][i] = i + 1;
        next[0][i] = a[i];
    }

    for(int i = 1; i < 30; i++) 
    {
        for(ll j = 0; j < n; j++) 
        {
            lift[i][j] = lift[i-1][j] + lift[i-1][next[i-1][j]];
            next[i][j] = next[i-1][next[i-1][j]];
        }
    }

    while(q--) 
    {
        ll t,b;
        cin >> t >> b;
        b--;
        ll ans = 0;
        for(int i = 30; i >= 0; i--) 
        {
            if((1<<i) & t) 
            {
                // t -= (1<<i);
                ans += lift[i][b];
                b = next[i][b];
            }
        }
        cout << ans << endl;
    }    

    return 0;
}