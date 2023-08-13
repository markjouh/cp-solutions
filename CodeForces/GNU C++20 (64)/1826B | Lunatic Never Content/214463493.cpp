#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vi a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        int ans = 0;
        rep(i, 0, n / 2) {
            int x = a[i], y = a[n - i - 1];
            if (x < y) {
                swap(x, y);
            }
            ans = gcd(ans, x - y);
        }
        cout << ans << '\n';
    }
}