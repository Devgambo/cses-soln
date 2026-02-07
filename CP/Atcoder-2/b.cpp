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

int main() {
    fast_io();
    int n, m;
    cin >> n >>m;
    map<int, vector<int>> mp;
    for(int i=0; i<n; i++){
        int ai, bi;
        cin >>ai >>bi;
        mp[ai].push_back(bi);
    }

    for(auto x: mp){
        int sm = 0;
        int sz=0;
        for(int i:x.second){
            sm+=i;
            sz++;
        }
        double ans = static_cast<double>(sm)/sz;
        cout <<fixed<<setprecision(5)<<ans<<endl;

    }

    return 0;
}