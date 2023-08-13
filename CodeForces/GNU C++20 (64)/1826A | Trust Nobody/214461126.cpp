#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n + 1) {
        int good = 0, bad = 0;
        rep(j, 0, n) {
            (a[j] <= i ? good : bad)++;
        }
        if (bad == i) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}