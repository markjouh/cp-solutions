#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ckmin(a, b) a = min(a, b)
#define ckmax(a, b) a = max(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;
        if (a == b) {
            cout << 0 << '\n';
        } else if (abs(a - b) >= x) {
            cout << 1 << '\n';
        } else if ((abs(a - l) >= x && abs(l - b) >= x) || (abs(a - r) >= x && abs(b - r) >= x)) {
            cout << 2 << '\n';
        } else if ((abs(a - r) >= x && abs(l - r) >= x && abs(l - b) >= x) || (abs(a - l) >= x && abs(l - r) >= x && abs(b - r) >= x)) {
            cout << 3 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}