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

ll insertSm(vector<pll> &vec, ll l, ll r) {
    vec.push_back({l, r});
    sort(vec.begin(), vec.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        return a.first < b.first;
    });

    vector<pll> merged;
    merged.push_back(vec[0]);
    
    for (int i = 1; i < vec.size(); ++i) {
        pll &last = merged.back();
        pll curr = vec[i];

        if (curr.ff <= last.ss) { 
            last.ss = max(last.ss, curr.ss);
        } else {
            merged.push_back(curr);
        }
    }

    ll total = 0;
    for (auto p : merged) {
        total += (p.ss - p.ff + 1);
    }
    vec = merged;
    return total;
}


int main() {
    fast_io();
    long long n , q;
    cin >> n >> q;
    vector<pll> qry;
    for(int i=0; i<q; i++){
        ll l,r;
        cin >> l >> r;
        qry.push_back({l,r});
    }

    vector<pll> vec;

    for(auto a : qry){
        ll l = a.ff;
        ll r = a.ss;
        ll ans = insertSm(vec, l, r);
        cout << (n - ans) << endl;
    }

    return 0;
}