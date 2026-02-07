#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll ILL=2167167167167167167;
const ll INF=2100000000;
#define rep(i,a,b) for (ll i=(ll)(a);i<(ll)(b);i++)
#define all(p) p.begin(),p.end()

ll digit_count(ll a){
    ll tmp = 1;
    ll c = 1;
    ll res = 0;
    while (tmp * 10 <= a){
        res += tmp * 9 * c;
        tmp *= 10;
        c++;
    }
    res += (a - tmp) * c;
    return res;
}

const ll N = 16;
ll po[N];

ll sumOfDigits(ll n) {
    if (n < 10)
        return n * (n + 1) / 2;

    // count digits
    ll d = 0, x = n;
    while (x > 0) {
        x /= 10;
        d++;
    }

    vector<ll> po(d+1, 1);
    for (ll i = 1; i <= d; i++)
        po[i] = po[i-1] * 10;


    vector<ll> a(d+1);
    a[0] = 0, a[1] = 45;
    for (ll i = 2; i <= d; i++)
        a[i] = a[i-1] * 10 + 45 * po[i-1];

    ll p = po[d-1];         
    ll msd = n / p;

    return msd * a[d-1] +
           (msd * (msd - 1) / 2) * p +
           msd * (1 + n % p) +
           sumOfDigits(n % p);
}

void solve(){
    ll N;
    cin >> N;
    ll L = 1, R = N + 1;
    while (R - L > 1){
        ll M = (L + R) / 2;
        if (digit_count(M) < N) L = M;
        else R = M;
    }
    ll ans = sumOfDigits(L-1);
    N -= digit_count(L);
    string S = to_string(L);
    rep(rp, 0, N) ans += (S[rp] - '0');
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    po[0] = 1;
    for(ll i = 1 ; i < N ; i++) po[i] = po[i-1] * 10;
    ll t = 1;
    cin >> t;
    rep(i, 0, t) solve();
}