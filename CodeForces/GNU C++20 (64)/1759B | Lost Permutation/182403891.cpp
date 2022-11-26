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
 
const string y = "Yes";
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int m, s;
        cin >> m >> s;
        vector<bool> have(51);
        int mx = 0;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            have[x] = true;
            ckmax(mx, x);
        }
        for (int i = 1; i <= mx; i++) {
            if (!have[i]) {
                s -= i;
            }
        }
        while (s > 0) {
            s -= ++mx;
        }
        cout << (s == 0 ? "YES\n" : "NO\n");
    }
}