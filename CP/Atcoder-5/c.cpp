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
    for(int i=0; i<n ; i++){
        cin >> a[i];
    }

    // ele, freq
    stack<pair<int, int>> s;
    for(int i=0; i<n; i++){
        int ele = a[i];
        if(s.size()>0){
            int top = s.top().first;
            int fr = s.top().second;
            if(ele==top){
                s.push({ele , fr+1});
                if(s.top().second == 4){
                    int k = 0;
                    while(k<4){
                        s.pop();
                        k++;
                    }
                }
            }else{
                s.push({ele, 1});
            }
        }else{
            s.push({ele, 1});
        }
    }

    cout << s.size();
    return 0;
}