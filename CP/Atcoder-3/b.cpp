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
    int ans = 0;
    vi A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    for(int i=0; i<n; i++){
        int sm=A[i];
        for(int j=i+1; j<n; j++){
            sm+=A[j];
            bool fg = true;
            for(int k=i; k<=j; k++){
                if(sm%A[k]==0){
                    fg = false;
                }
            }
            if(fg){
                ans++;
            }

        }
    }


    cout << ans;
    return 0;
}