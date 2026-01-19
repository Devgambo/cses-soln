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

void fun(ll n, ll t){
    vll a , b;
    while(t>=n){
        a.push_back(n);
        t = t-n;
        n--;
    }
    if(t>0){
        a.push_back(t);
    }
    for(int i=1; i<=n; i++){
        if(i==t)    continue;
        b.push_back(i);
    }

    cout << a.size()<<endl;
    for(int i:a)    cout<<i<<" ";

    cout <<endl;

    cout << b.size()<<endl;
    for(int i:b)    cout<<i<<" ";

}

int main() {
    fast_io();
    ll n;
    cin >> n;
    ll sm = n*(n+1) / 2;
    if(sm%2==1){
        cout << "NO"<<endl;
        return 0;
    }else{
        ll tar = sm / 2;
        cout << "YES"<<endl;
        fun(n,tar);
    }
    return 0;
}