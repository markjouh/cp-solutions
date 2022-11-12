#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
// warmup
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, h, m;
        cin >> n >> h >> m;
        int t = h * 60 + m;
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            int ch, cm;
            cin >> ch >> cm;
            int ct = ch * 60 + cm;
            if (ct >= t) {
                ans = min(ans, ct - t);
            }
            ans = min(ans, ct + 1440 - t);
        }
        cout << ans / 60 << ' ' << ans % 60 << '\n';
    }
}