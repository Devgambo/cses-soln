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


void fun(vector<vector<int>> vec, int n, int h){
    bool fg = true;
    pair<int,int> range = {h,h};
    int prevt = 0;
    for(auto x: vec){
        int dt = x[0] - prevt;
        range.first = max(range.first - dt, x[1]);
        range.second = min(range.second + dt, x[2]);
        if(range.first > range.second) fg = false;
        prevt = x[0];
    }
    if(fg){
        cout << "Yes" << endl;
    } else{
        cout << "No"<< endl;
    }
    return;
}


int main() {
    fast_io();
    int t;
    cin >> t ;
    for(int i=0; i<t; i++){
        int n,h;
        cin >> n >> h;
        vector<vector<int>> vt(n);
        for(int j=0; j<n; j++){
            int t,l,u;
            cin >>t>>l>>u;
            vt[j] = {t,l,u};
        }
        fun(vt, n, h);
    }

    return 0;
}