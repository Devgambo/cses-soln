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
    ll t;
    cin >> t; 
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        string dubs = s;
        sort(dubs.begin(), dubs.end());
        if(dubs == s){
            cout << "Bob"<< endl;
            continue;
        }

        vi ans;
        int i = 0, j = n-1;
        while(i<j){
            while(i < n && s[i]!='1')    i++;
            while(j >= 0 && s[j]!='0')   j--;
            if(i>=j)
                break;
            ans.pb(i+1);
            ans.pb(j+1);
            i++; j--;
        }

        sort(ans.begin(), ans.end());

        cout << "Alice" << endl;
        cout << ans.size() << endl;
        for(int i:ans)  cout << i << " ";
        cout << endl;
    }
    return 0;
}