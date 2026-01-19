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

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}



//move n discs from a to c via b
void TOH(int n, int a, int b, int c){
    if(n==1){
        cout << a << " " << c << '\n';
        return;
    }
    TOH(n-1, a, c, b);
    cout << a << " " << c << '\n';
    TOH(n-1, b, a, c);
}


int main()
{
    fast_io();
    int n;
    cin >> n;
    cout << (1LL << n) - 1 << '\n'; // print number of moves
    TOH(n, 1, 2, 3);
    return 0;
}