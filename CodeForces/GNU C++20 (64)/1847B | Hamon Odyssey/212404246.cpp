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
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int best = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        best = best & a[i];
    }
    if (best != 0) {
        cout << 1 << '\n';
        return;
    }
    int cur = INT_MAX;
    int ans = 0;    
    for (int i = 0; i < n; i++) {
        cur = cur & a[i];
        if (cur == 0) {
            ans++;
            cur = INT_MAX;
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}