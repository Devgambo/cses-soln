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

void f(int n, vll v){
    ll ans=0;
    int i=0,j=1,k=2;
    while(k<n){
        int od = v[i]+v[k];
        int ev = v[j];
        if(ev>=od){
            i+=2;
            j+=2;
            k+=2;
            continue;
        }
        else{
            int dif = od-ev;
            if(dif > v[k]){
                v[k] = 0;
                dif = dif - v[k];
                ans+=v[k];
                v[j] += dif;
                ans += dif;
                i+=2;
                j+=2;
                k+=2;
                continue;
            }else{
                v[k] = v[k]-dif;
                ans+=dif;
                i+=2;
                j+=2;
                k+=2;
                continue;
            }
        }
    }

    if(n%2==0){
        if(v[n-2]>v[n-1]){
            ans+=v[n-2]-v[n-1];
        }
    }

    cout<<ans;
    return;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vll v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];
        f(n,v);
        cout<<endl;
    }

    return 0;
}