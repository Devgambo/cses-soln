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

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define trav(a, x) for(auto& a : x)

#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


int dfs(int node, vvi &children, vi &subordinates) {
    int count = 0;
    for(int child : children[node]) {
        count += 1 + dfs(child, children, subordinates);
    }
    subordinates[node] = count;
    return count;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    
    vvi children(n + 1);
    
    // Read bosses for employees 2 to n
    for(int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        children[boss].pb(i);
    }
    
    vi subordinates(n + 1);
    dfs(1, children, subordinates);
    
    // Output subordinates count for each employee
    for(int i = 1; i <= n; i++) {
        cout << subordinates[i];
        if(i < n) cout << " ";
    }
    cout << endl;
    
    return 0;
}