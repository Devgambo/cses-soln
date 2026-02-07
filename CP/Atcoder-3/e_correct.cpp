#include <bits/stdc++.h>

#define loop(i, l, r) for(int i = (l); i < (r); ++i)
#define pool(i, l, r) for(int i = (l); i > (r); --i)
#define debug(x) cerr << #x << ": " << x << endl;
using namespace std;
const int MAXN = 200005;
int n,q;
int l[MAXN],r[MAXN];
using pii = pair<int,int>;
set<pii> intervals;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    int black = 2;
    intervals.insert({0,0});
    intervals.insert({n+1,n+1});
    loop(i,0,q){
        cin>>l[i]>>r[i];
        auto a = intervals.upper_bound({l[i],-1e9});
        a--;
        if(a->second<l[i]){
            a++;
        }
        auto b = intervals.upper_bound({r[i],1e9});
        b--;
        int newl = min(l[i],a->first);
        int newr = max(r[i],b->second);
        long long sum = 0;
        auto it = a;
        while(b->first>=it->first){
            sum += (it->second - it->first +1);
            auto toerase = it;
            it++;
            intervals.erase(toerase);
        }
        black+=newr - newl +1 - sum;
        intervals.insert({newl,newr});
        cout<<n-(black-2)<<endl;
    }
    
    return 0;
}