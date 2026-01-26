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


ll gcd(ll a, ll b){
    if(b==0)    return a;
    return gcd(b,a%b);
}

ll findgcdOfdif(vll a){
    stack<ll> s;
    for(int i=1; i<a.size(); i++){
        s.push(a[0] - a[i]);
    }

    while(s.size()!=1){
        ll a1 = s.top();    s.pop();
        ll b1 = s.top();    s.pop();
        s.push(gcd(a1,b1));
    }

    return s.top();

}


int main() {
    fast_io();
    int n, m;
    cin >> n >> m;
    vll a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    if(n==1){
        for(int i=0; i<m; i++){
            cout << (a[0] + b[i]) <<" ";
        }
        return 0;
    }

    ll d = findgcdOfdif(a);

    for(int i=0; i<m; i++){
        ll ans = gcd(a[0] + b[i], d);
        cout << abs(ans) << " ";
    }
    return 0;
}