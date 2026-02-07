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
    int t;
    cin >> t; 
    while(t--){
        int n,h,l;
        cin >> n >> h >> l;
        vi a(n);
        for(int i=0; i<n; i++)  cin >> a[i];

        if(l>h){
            swap(l,h);
        }

        sort(a.begin(), a.end());

        map<pii, int> mp;
        int i =0, j=n-1 ;
        while(i<j){
            if(a[j]>h) { j--; continue; }
            if(a[i]>l) break;
            if(a[j]<=h && a[i] <= l){
                mp[{a[j--], a[i++]}]++;
            }
        }

        int ans = 0;
        for(auto i: mp){
            ans += i.second;
        }

        cout << ans << endl;
    }
    return 0;
}