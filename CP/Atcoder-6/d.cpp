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
    
    map<int, int> total;
    for(int i = 0; i < n; i++){
        total[a[i]]++;
    }
    
    ll ans = 0;
    map<int, int> left;
    
    for(int j = 0; j < n; j++){
        if(a[j] % 5 == 0){
            int t = a[j] / 5;
            int t7 = 7 * t;
            int t3 = 3 * t;

            ans += (ll)left[t7] * left[t3];
            int right_7 = total[t7] - left[t7];
            int right_3 = total[t3] - left[t3];

            ans += (ll)right_7 * right_3;
        }
        left[a[j]]++;
    }

    cout << ans;

    return 0;
}