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


void f(int n, vi a, vi b){
    int ans = 0;
    bool f = true;
    while(f){
        int i = 0;
        bool f2=true;
        bool f3=true;
        bool f4=true;
        for(; i<n; i++){
            if(a[i]>b[i]){
                f2=false;
                f3=false;
                a[i]--;
            }
            if(a[i]<b[i]){
                f4=false;
                a[i]++;
            }
            if(!f3 && !f4){
                break;
            }
        }
        ans++;
        if(f2){
            break;
        }
    }
    cout<<ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        vi b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        f(n,a,b);
        cout<<endl;
    }

    return 0;
}
