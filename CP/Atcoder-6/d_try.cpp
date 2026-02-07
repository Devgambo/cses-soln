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
    cin >> n;
    vi a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int ans = 0;

    map<int, int> mp;
    for(int i:a){
        if(i%7==0){
            mp[i]++;
        }else if(i%3==0){
            mp[i]++;
        }else if(i%5==0){
            int f = i/5;
            if(mp.count(3*f) && mp.count(7*f)){
                ans += (mp[3*f] * mp[7*f]);
            }
        }
    }
    reverse(a.begin(), a.end());
    map<int, int> mp2;
    for(int i:a){
        if(i%7==0){
            mp2[i]++;
        }else if(i%3==0){
            mp2[i]++;
        }else if(i%5==0){
            int f = i/5;
            if(mp2.count(3*f) && mp2.count(7*f)){
                ans += (mp2[3*f]*mp2[7*f]);
            }
        }
    }

    cout << ans;


    return 0;
}