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

int n, m;

class Disjoint{
private:
    int n;
    vi size;
    vi par;
    int maxsz=1;
public: 
    Disjoint(int n){
        this->n = n;
        size.resize(n+1, 1);
        par.resize(n+1);
        for(int i=1; i<=n; i++)  par[i]=i;
    }

    int findP(int nd){
        if(par[nd]==nd) return nd;
        return par[nd] = findP(par[nd]);
    }

    int noOfComp(){
        return n;
    }
    
    int maxSize(){
        return maxsz;
    }

    void unionBySize(int a, int b){
        int ap = findP(a);
        int bp = findP(b);
        if(ap==bp)  return;
        if(size[ap] > size[bp]){
            size[ap] += size[bp];
            par[bp] = ap;
            maxsz = max(maxsz, size[ap]);
            n--;
        }else{
            size[bp] += size[ap];
            par[ap] = bp;
            maxsz = max(maxsz, size[bp]);
            n--;
        }
    }
};

int main() {
    fast_io();
    cin >> n >> m;
    vpii g;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        g.pb({a,b});
    }   

    Disjoint ds(n);
    for(auto it : g){
        ds.unionBySize(it.ff, it.ss);
        int no = ds.noOfComp();
        int sz = ds.maxSize();
        cout << no <<" "<< sz << '\n';
    }
    return 0;
}