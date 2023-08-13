#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
typedef long long ll;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
void solve() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    for (int i = 1; i <= n; i++) {
        cout << max(sz(st), i) << ' ';
    }
    cout << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
 
/*
 
Each distinct value in a must contribute at least 1 to the sum
The problem is that we may have to break sets of the same value up to be able to give all children at least 1 powerup
 
*/