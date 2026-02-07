#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long ll;
const int MOD = 1e9+7;

#define PRIYANSHU ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    PRIYANSHU
    
    ll n;
    cin >> n;
    vector <ll> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for(ll i = 1 ; i <= n ; i++) cin >> a[i];
	for(ll i = 1 ; i <= n ; i++) cin >> b[i];
	for(ll i = 1 ; i <= n ; i++) cin >> c[i];
    
    //prefix sum
    for(ll i = 1 ; i <= n ; i++) a[i] = a[i-1] + a[i];
    for(ll i = 1 ; i <= n ; i++) b[i] = b[i-1] + b[i];
    for(ll i = 1 ; i <= n ; i++) c[i] = c[i-1] + c[i];

    vector <ll> p1(n+1, 0), p2(n+1, 0), mp2(n+1, 0);

    //further simplication
	for(ll i = 1 ; i <= n ; i++) p1[i] = a[i] - b[i];
	for(ll i = 1 ; i <= n ; i++) p2[i] = b[i] - c[i];

    //precumputing maxpY[i] (i - n-1)
	mp2[n-1] = p2[n-1];
	for(ll i = n-2 ; i >= 0 ; i--) mp2[i] = max(mp2[i+1], p2[i]);


	ll ans = 0;
	for(ll x = 1 ; x < n-1 ; x++)
	{
		ll cur = c[n] + p1[x] + mp2[x+1];
		ans = max(ans, cur);
	}	

	cout << ans << endl;

    return 0;
}