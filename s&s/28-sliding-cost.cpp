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
    // cost = (mid*szLo - sm(lo) + sm(hi) - mid*szHi); 
    ll sumlo = 0;
    ll sumhi = 0;
    vll ans;

    auto rebalance = [&]() {
        while (lo.size() > hi.size() + 1)
        {
            hi.insert(*lo.rbegin());
            sumhi += (*lo.rbegin());
            sumlo -= (*lo.rbegin());
            lo.erase(prev(lo.end()));

        }

        while (lo.size() < hi.size())
        {
            lo.insert(*hi.begin());
            sumlo += *hi.begin();
            sumhi -= *hi.begin();
            hi.erase(hi.begin());
        }
    };

    // auto getMedian = [&]() -> double {
    //     if (k % 2)
    //         return (double)*lo.rbegin();
    //     return ((long long)*lo.rbegin() + *hi.begin()) / 2.0;
    // };


    for (int i = 0; i < n; i++){
        if(lo.empty() || v[i] <= *lo.rbegin()){
            lo.insert(v[i]);
            sumlo += v[i];
        }else{
            hi.insert(v[i]);
            sumhi += v[i];
        }

        rebalance();


        if(i>=k-1){
            ll median = *lo.rbegin();
            ans.pb(((ll)lo.size() * median - sumlo) + (sumhi - (ll)hi.size() * median));

            //remove the last ele
            ll out = v[i-k+1];
            auto it = lo.find(out);
            if(it != lo.end()){
                sumlo -= *it;
                lo.erase(it);
            }
            else{
                it = hi.find(out);
                if (it != hi.end()) {
                    sumhi -= *it;
                    hi.erase(it);
                }
            }
            rebalance();
        }
    }

    for(ll i:ans){
        cout << i <<" ";
    }

    return 0;
}