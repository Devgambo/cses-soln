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


const int MAXN = 1000001;
bool is_prime[MAXN];

//sieve of eratosthenes to precalc primes
void sieve(){
    fill(is_prime, is_prime + MAXN, true);
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2; i * i < MAXN; i++){
        if(is_prime[i]){
            for(int j = i * i; j < MAXN; j += i){
                is_prime[j] = false;
            }
        }
    }
}

bool chksqr(ll x){
    // check if x is a perfect square and its sqrt is prime
    ll sq = sqrt(x);
    
    // Check perfect square
    if(sq * sq != x) return false;
    
    // Check if sqrt is within range and is prime
    if(sq < MAXN) return is_prime[sq]; 
    return false;
}
int main() {
    fast_io();
    sieve(); // Precompute primes
    
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for(ll i : a){
        if(chksqr(i)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}