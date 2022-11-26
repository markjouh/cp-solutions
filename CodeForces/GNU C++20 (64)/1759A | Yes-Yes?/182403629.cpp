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
        string s;
        cin >> s;
        bool ans = false;
        for (int i = 0; i < 3; i++) {
            bool ok = true;
            for (int j = 0; j < sz(s); j++) {
                ok &= s[j] == y[(i + j) % 3];
            }
            if (ok) {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}