#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
#define pb push_back
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << (x) << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// ques : given n : no of courses, a and b vectors where a[i]->b[i] connected, a[i] is prereq of b[i]
// return maximum no of courses which are valid.
// a valid course is a course whose all the prerequesists are completed. 
// graph can contain self loops and cycles.

// eg:
// int n = 5; vi from = {1,2,4,5}; vi to = {2,3,5,4};
// here ans is 4 as 1,2,3 can be valid and for 4,5 there can be only 1 valid.

// n = 7;
// from = {1,2,3,2,7,6,5,5}
// to = {2,3,4,7,6,5,3,7}
// ans = 5 (we need to make 5 as invalid complete)


void dfs1(int nd, vvi &g, vi &vis, stack<int> &finishOrder){
    vis[nd] = 1;
    for(int neighbor : g[nd]){
        if(!vis[neighbor]){
            dfs1(neighbor, g, vis, finishOrder);
        }
    }
    finishOrder.push(nd);
}

void dfs2(int nd, vvi &revG, vi &vis, int &sccSize){
    vis[nd] = 1;
    sccSize++;
    for(int neighbor : revG[nd]){
        if(!vis[neighbor]){
            dfs2(neighbor, revG, vis, sccSize);
        }
    }
}

int maxNoOfValidCourses(int n, vi a, vi b){
    vvi g(n+1), revG(n+1);
    
    for(int i=0; i<a.size(); i++){
        if(a[i] == b[i]) continue; // Skip self-loops
        g[a[i]].pb(b[i]);
        revG[b[i]].pb(a[i]);
    }

    // Step 1: DFS on original graph to get finish times
    vi vis(n+1, 0);
    stack<int> finishOrder;
    
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs1(i, g, vis, finishOrder);
        }
    }

    // Step 2: DFS on reversed graph in order of decreasing finish time
    fill(vis.begin(), vis.end(), 0);
    int numCycleNodes = 0;
    
    while(!finishOrder.empty()){
        int node = finishOrder.top();
        finishOrder.pop();
        
        if(!vis[node]){
            int sccSize = 0;
            dfs2(node, revG, vis, sccSize);
            
            // If SCC has more than 1 node, it's a cycle - we lose 1 node
            if(sccSize > 1){
                numCycleNodes++;
            }
        }
    }

    return n - numCycleNodes;
}



int main() {
    fast_io();
    int n = 6;
    vi from = {1,2,4,5,6};
    vi to = {2,3,5,6,4};

    int ans = maxNoOfValidCourses(n,from,to);

    cout << ans;
    return 0;
}