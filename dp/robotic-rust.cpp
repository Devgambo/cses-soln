// div-4-1074-e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vc = vector<char>;
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
        int n,m,k;
        cin >> n >> m >> k;
        vll a(n);
        set<ll> b;
        for(int i=0; i<n; i++)   cin >> a[i];
        for(int i=0; i<m; i++){
            int x; cin >> x; b.insert(x);
        }
        string s;   cin >> s;

        set<pii> left, right;
        vector<pii> l_r;
        for(int i=0; i<n; i++){
            auto it = b.upper_bound(a[i]);
            int bef = INT_MAX, aft = INT_MAX;
            if(it != b.end()) aft = (*it) - a[i];
            if(it != b.begin()){ it--; bef = a[i] - (*it); }

            left.insert({bef,i});
            right.insert({aft,i});
            l_r.push_back({bef, aft});
        }


        int cnt = 0;
        int ans = n;
        for(char c:s){
            if(c=='R') cnt++;
            else cnt--;
            
            if(cnt > 0){
                while(!right.empty() && cnt >= (*(right.begin())).first){
                    auto i = (*(right.begin())).second;
                    right.erase(right.begin());
                    left.erase(left.find({l_r[i].first,i}));
                    ans--;
                }
            }   
            if(cnt < 0){
                while(!left.empty() && (-cnt) >= (*(left.begin())).first){
                    auto i = (*(left.begin())).second;
                    left.erase(left.begin());
                    right.erase(right.find({l_r[i].second,i}));
                    ans--;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}
