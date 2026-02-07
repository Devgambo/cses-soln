#include <bits/stdc++.h>

#define loop(i, l, r) for(int i = (l); i < (r); ++i)
#define pool(i, l, r) for(int i = (l); i > (r); --i)
#define debug(x) cerr << #x << ": " << x << endl;
using namespace std;
int n;
const int MAXN = 200005;
int x[MAXN];
int r[MAXN];
unordered_map<int,int> edges;
unordered_map<long long,int> oldToNew;
struct disjoint_set{
    vector<int> ancestor;
    vector<int> rank;
    disjoint_set(int n){
        ancestor.resize(n);
        rank.resize(n);
        loop(i,0,n){
            ancestor[i] = i;
            rank[i] = 1;
        }
    }
    void unite(int x,int y){
        x = find(x);
        y = find(y);

        if(x==y){
            return;
        }
        if(rank[x]<rank[y]){
            ancestor[x] = y;
            rank[y] = rank[y]+rank[x];
        }else{
            ancestor[y] = x;
            rank[x] = rank[y]+rank[x];
        }

    }
    int find(int x){
        if(ancestor[x]==x){
            return x;
        }else{
            return ancestor[x] = find(ancestor[x]);
        }
    }
};
unordered_map<int,pair<int,int>> components;// component index, <number of edges, number of nodes>
disjoint_set d(2*MAXN);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<long long> points;
    loop(i,0,n){
        cin>>x[i]>>r[i];
        points.push_back(x[i]-r[i]);
        points.push_back(x[i]+r[i]);
    }
    sort(points.begin(),points.end());
    points.erase(unique(points.begin(),points.end()),points.end());
    for(int i = 0; i < points.size(); i++){
        oldToNew[points[i]] = i;
    }
    loop(i,0,n){
        edges[oldToNew[x[i]-r[i]]]++;
        edges[oldToNew[x[i]+r[i]]]++;
        d.unite(oldToNew[x[i]-r[i]],oldToNew[x[i]+r[i]]);
    }
    loop(i,0,points.size()){
        int root = d.find(i);
        if(components.find(root)==components.end()){
            components[root] = {0,0};               //to init
        }
        components[root].second++;       // Count Nodes (Vertices)
        components[root].first += edges[i]; // Sum of Degrees
    }

    
    // p.second: The number of Vertices(V) in the component.
    // p.first: The sum of degrees. By the Handshaking Lemma, the number of Edges(E) is p.first / 2.

    int ans = 0;
    for(auto &[_,p]:components){
        if(p.first/2 >= p.second){ // If Edges >= Vertices
            ans += p.second;       // Add Vertices
        } else {                   // If Edges < Vertices (Implies Tree)
            ans += p.second - 1;   // Add Vertices - 1
        }
    }
    cout<<ans<<endl;
    return 0;
}
