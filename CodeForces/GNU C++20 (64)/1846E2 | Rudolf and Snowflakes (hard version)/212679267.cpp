#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
 
set<ll> st; // ~64 * 1e6
 
void solve() {
    ll n;
    cin >> n;
    if (st.find(n) != st.end()) {
        cout << "YES\n";
        return;
    }
    ll lo = 1e6 + 1, hi = 1e9;
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        ll res = 1 + mid + mid * mid;
        (res <= n ? lo : hi) = mid;
    }
    cout << (1 + lo + lo * lo == n ? "YES\n" : "NO\n");
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    for (ll i = 2; i <= 1e6; i++) {
        __int128_t sum = 1 + i + i * i;
        __int128_t cur = i * i;
        while (sum <= 1e18) {
            st.insert(sum);
            cur *= i;
            sum += cur;
        }
    }
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}