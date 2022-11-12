#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x <= k && i > k) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}