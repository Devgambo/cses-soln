#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using bd = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vdb = vector<double>;
using vll = vector<ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define pb push_back
#define ff first
#define ss second

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fast_io();
    int n,k;
    cin >> n >> k;
    vll v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    multiset<ll> lo;
    multiset<ll> hi;
    vll ans;

    auto rebalance = [&]() {
        if (lo.size() > hi.size() + 1)
        {
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }

        if (lo.size() < hi.size())
        {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    };

    auto getMedian = [&]() -> ll {
        return *lo.rbegin();
    };

    for (int i = 0; i < n; i++){
        if(lo.empty() || v[i] <= *lo.rbegin()){
            lo.insert(v[i]);
        }else{
            hi.insert(v[i]);
        }

        rebalance();

        if(i>=k-1){
            ans.pb(getMedian());

            //remove the last ele
            ll out = v[i-k+1];
            if(lo.find(out)!=lo.end()){
               lo.erase(lo.find(out));
            }
            else
                hi.erase(hi.find(out));
                
            rebalance();
        }
    }

    for(ll i:ans){
        cout << i <<" ";
    }

    return 0;
}