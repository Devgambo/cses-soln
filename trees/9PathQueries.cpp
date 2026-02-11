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

#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int n, q, N; // N = 2*n (euler tour size)
vll val;
vvi adj;
vi tin, tout;
int timer = 0;
vll seg; // segment tree (1-indexed, size 4*N)

// --- Segment Tree (point update + range sum query) ---
void build(int node, int lo, int hi, vll &a) {
    if (lo == hi) {
        seg[node] = a[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*node, lo, mid, a);
    build(2*node+1, mid+1, hi, a);
    seg[node] = seg[2*node] + seg[2*node+1];
}

void seg_update(int node, int lo, int hi, int pos, ll v) {
    if (lo == hi) {
        seg[node] = v;
        return;
    }
    int mid = (lo + hi) / 2;
    if (pos <= mid) seg_update(2*node, lo, mid, pos, v);
    else            seg_update(2*node+1, mid+1, hi, pos, v);
    seg[node] = seg[2*node] + seg[2*node+1];
}

ll seg_query(int node, int lo, int hi, int l, int r) {
    if (r < lo || hi < l) return 0;
    if (l <= lo && hi <= r) return seg[node];
    int mid = (lo + hi) / 2;
    return seg_query(2*node, lo, mid, l, r) +
           seg_query(2*node+1, mid+1, hi, l, r);
}

// --- Euler Tour (+val on entry, -val on exit) ---
void euler(int nd, int par) {
    tin[nd] = ++timer;   // entry: +val[nd]
    for (int i : adj[nd]) {
        if (i != par)
            euler(i, nd);
    }
    tout[nd] = ++timer;  // exit: -val[nd]
}

void update(int s, ll x) {
    val[s] = x;
    seg_update(1, 1, N, tin[s], x);    // +val at entry
    seg_update(1, 1, N, tout[s], -x);  // -val at exit
}

ll pathSum(int s) {
    // prefix sum up to tin[s] = sum of ancestors' values + val[s]
    return seg_query(1, 1, N, 1, tin[s]);
}

int main() {
    fast_io();
    cin >> n >> q;
    N = 2 * n; // euler tour has 2n positions (entry + exit)
    adj.resize(n+1);
    val.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    for(int i=1; i<=n; i++)  cin >> val[i];
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    euler(1, -1);

    // Build flat array: +val at tin[i], -val at tout[i]
    vll flat(N+1, 0);
    for(int i = 1; i <= n; i++) {
        flat[tin[i]] = val[i];
        flat[tout[i]] = -val[i];
    }
    seg.resize(4*(N+1), 0);
    build(1, 1, N, flat);

    while(q--){
        int ty;
        cin >> ty;
        if(ty==1){
            int s;
            ll x;
            cin >> s >> x;
            update(s, x);
        }else{
            int s;
            cin >> s;
            cout << pathSum(s) << '\n';
        }
    }
    
    
    return 0;
}