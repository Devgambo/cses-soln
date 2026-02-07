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


void f(int n,int k, multiset<int> S, multiset<int> T){
    int maxele = *prev(T.end());
    int minele = *T.begin();   

    for(int i:S){
        if(T.find(i)!=T.end()){
            T.erase(T.find(i));
            continue;
        }
        int cur1 = i;
        bool f=false;
        while(cur1 <= maxele){
            cur1+=k;
            if(T.find(cur1)!=T.end()){
                T.erase(T.find(cur1));
                f=true;
                break;
            }
        }
        if(!f){
            int cur2 = i;
            bool f2=true;
            while(cur2 >= -1 * maxele || cur2 >= minele){
                cur2 = cur2 - k;
                int tof = abs(cur2);
                if(T.find(tof)!=T.end()){
                    T.erase(T.find(tof));
                    break;
                }
                if(T.find(cur2)!=T.end()){
                    T.erase(T.find(cur2));
                    break;
                }
            }
        }
    }
    if(T.empty()){
        cout<<"YES";
    }
    else 
        cout<<"NO";

}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        multiset<int> S;
        multiset<int> T;

        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            S.insert(x);
        }
        for(int i = 0; i < n; i++) {
            cin >> x;
            T.insert(x);
        }

        f(n, k, S, T);
        cout << endl;
    }

    return 0;
}
