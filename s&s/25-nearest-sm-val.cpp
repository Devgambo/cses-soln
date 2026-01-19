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
    vector<ll> t(n);
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && t[st.top()] >= t[i]){
            st.pop();
        }
        if(st.empty()){
            cout << 0 << " ";
        } else {
            cout << st.top() + 1 << " ";
        }
        st.push(i);
    }

    return 0;
}