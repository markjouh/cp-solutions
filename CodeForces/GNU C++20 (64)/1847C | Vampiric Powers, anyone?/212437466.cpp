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
    vector<bool> have(256);
    have[0] = true;
    int pref = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pref ^= x;
        have[pref] = true;
        for (int j = 0; j < 256; j++) {
            if (have[pref ^ j]) {
                ans = max(ans, j);
            }
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