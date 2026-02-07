#include <bits/stdc++.h>

#define loop(i, l, r) for(int i = (l); i < (r); ++i)
#define pool(i, l, r) for(int i = (l); i > (r); --i)
#define debug(x) cerr << #x << ": " << x << endl;
using namespace std;
int n,m;
const int MAXN = 300005;
bool color[MAXN];
vector<int> graph[MAXN];
void update_color(int v){
    if(color[v]) return;
    color[v] = true;
    for(auto to:graph[v]){
        if(!color[to]){
            update_color(to);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    loop(i,0,m){
        int u,v;
        cin>>u>>v;
        graph[v].push_back(u);
    }
    int q;
    cin>>q;
    loop(i,0,q){
        int t,v;
        cin>>t>>v;
        if(t==1){
            if(color[v]) continue;
            update_color(v);
        }else{
            if(color[v]){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;    
            }
        }       
    }
    return 0;
}
