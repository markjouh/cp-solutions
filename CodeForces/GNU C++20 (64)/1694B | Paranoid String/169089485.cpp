#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
// warmup 2
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;
 
        ll ans = 0;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            if (d != prev) {
                ans += i;
                prev = d;
            }
        }
        cout << ans + n << '\n';
    }
}