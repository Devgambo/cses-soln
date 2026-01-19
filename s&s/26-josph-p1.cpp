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
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }

    while(!q.empty()){
        // Move the first child to the end (skip them)
        int skip = q.front();
        q.pop();
        q.push(skip);

        // Remove the second child
        int remove = q.front();
        q.pop();
        cout << remove << " ";
    }

    return 0;
}