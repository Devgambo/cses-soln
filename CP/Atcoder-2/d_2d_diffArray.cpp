#include <bits/stdc++.h>
#define loop(i, l, r) for(int i = (l); i < (r); ++i)
#define pool(i, l, r) for(int i = (l); i > (r); --i)
#define debug(x) cerr << #x << ": " << x << endl;
using namespace std;
int n;
const int MAXN = 2005;
int grid[MAXN][MAXN];
int sum[MAXN][MAXN];
const int MAXA = 200005;
int u[MAXA];
int d[MAXA];
int l[MAXA];
int r[MAXA];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    loop(i,0,n){
        cin>>u[i]>>d[i]>>l[i]>>r[i];
        grid[u[i]][l[i]]++;
        grid[u[i]][r[i]+1]--;
        grid[d[i]+1][l[i]]--;
        grid[d[i]+1][r[i]+1]++;
    }
    int total = 0;
    loop(i,1,MAXN){
        loop(j,1,MAXN){
            grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
            if(grid[i][j]==1){
                sum[i][j]++;
            }
            if(grid[i][j]>=1){
                total++;
            }
        }
    }
    loop(i,1,MAXN){
        loop(j,1,MAXN){
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    loop(i,0,n){
        int cnt = sum[d[i]][r[i]]-sum[d[i]][l[i]-1]-sum[u[i]-1][r[i]]+sum[u[i]-1][l[i]-1];
        cout<<2000*2000-(total-cnt)<<endl;
    }
    return 0;
}
