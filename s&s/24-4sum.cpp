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
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<ll, int>> t(n);
    for(int i=0; i<n; i++){
        cin >> t[i].first;
        t[i].second = i + 1;
    }

    sort(t.begin(), t.end());

    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            ll target = x - t[i].first - t[j].first;
            int k = j+1, l = n-1;
            while(k<l){
                ll sm = t[k].first + t[l].first;
                if(sm == target){
                    cout << t[i].second << " " << t[j].second << " " << t[k].second <<" "<< t[l].second <<endl;
                    return 0;
                }else if(sm<target){
                    k++;
                }else{
                    l--;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}