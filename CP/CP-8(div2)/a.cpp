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

// bool isSort(string s){
//     int fg = 0;
//     int fg2 = 0;
//     for(char c:s){
//         if(c=='1' && fg==0){
//             fg2++;
//             fg = 1;
//         }
//         if(c=='0'){
//             fg == 0;
//         }
//     }
//     return fg==1;
// }

void f(int n, string s){
    int i=0; 
    int j=n-1;
    int ans = 0;
    while(i<j){
        while(s[i]!='1' && i<j){
        i++;
        }
        while(s[j]!='0' && i<j){
        j--;
        }
        if(j-i >= 1){
            ans++;
        }
        i++;
        j--;
    }
    cout <<ans;
    return;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        f(n,s);
        cout<<endl;
    }

    return 0;
}