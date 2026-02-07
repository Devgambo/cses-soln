#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vpll = vector<pll>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second

#define debug(x) cerr << #x << " = " << (x) << endl

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
        int n;  cin >> n;
        vi a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int sz = n;
        int i = 0;
        while(a[i] == n){
            n--;
            i++;
        }

        int ind=0;
        for(int j=i; j<sz; j++){
            if(a[j]==n){
                ind=j;
                break;
            }
        }

        reverse(a.begin() + i, a.begin() + ind + 1);
        for(int i:a)   cout << i << " " ;
        cout << '\n';
    }
    return 0;
}