#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
// #define double long double
#define int long long
#define vi vector<int>
#define all(a) a.begin(),a.end()

void solve_first(){
    int n,m;
    cin>>n>>m;
    vector<vi>g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    queue<int>q;
    q.push(1);
    vector<int>vis(n+1);
    vis[1]=1;
    int dep=0;
    vector<char>color={'r','g','b'};
    vector<char>colors(n+1);
    //bfs
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            int y=q.front();
            q.pop();
            colors[y]=color[dep%3];
            for(auto &x:g[y]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        dep++;
    }
    //RGBRGBRGB
    for(int i=1;i<=n;i++){
        cout<<colors[i];
    }
    cout<<endl;
}
void solve_second(){
    int q;
    cin>>q;
    while(q--){
        map<char,int>m;
        int sz;
        cin>>sz;
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i+1;
        }
        if(m.size()==1){
            cout<<1<<endl;//all same 
        }
        else if(m.size()==2){
            char c='r'^'b'^'g';
            for(auto &p:m){
                c=(c^(p.first));
            }
            // cout<<c<<endl;
            // for(auto &p:m){
            //     cout<<p.first<<" "<<p.second<<endl;
            // }
            if(c=='g'){
               cout<<m['r']<<endl;     
            }
            else if(c=='b'){
                cout<<m['g']<<endl;
            }
            else{
                cout<<m['b']<<endl;
            }
        }
        else{
            assert(0);
        }
    }

}

int32_t main(){
    #ifdef MYPC2835
       freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //    freopen("error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int t=1;
    cin>>t;
    while(t--){
        if(s=="first"){
            solve_first();
        }
        else{
            solve_second();
        }
    }
}