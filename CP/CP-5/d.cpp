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


void f(ll n){
    ll ans=0;
    ll i = 1;
    ll fact=1;
    ll cnt=1;
    while(n>0){
          if(n==1){
            string s = to_string(i);
            ans+= stoi(s.substr(0,1));
        }
        ans+=i;
        i++;
        if(cnt%10==0){
            fact++;
        }
        cnt++;
        n=n-fact;
      
    }
    cout<< ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        f(n);
        cout<<endl;
    }

    return 0;
}