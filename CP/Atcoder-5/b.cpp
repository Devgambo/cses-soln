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
    int n,m;
    string S, T;
    cin >> n >> m;
    cin >> S >> T;

    int ans = INT_MAX;
    int i=0;
    while(i <= (n-m)){
        int cur = 0;
        int ori = i;
        int j=0;
        while(j<m){
            if(S[i] < T[j]){
                cur += (10 - (T[j++] - '0'));
                cur += ((S[i++] - '0'));
            }else{
                cur += (S[i++]-T[j++]);
            }
        }
        if(cur < 0) continue;
        ans = min(ans, cur);
        i = ori+1;
    }

    cout << ans;
    return 0;
}