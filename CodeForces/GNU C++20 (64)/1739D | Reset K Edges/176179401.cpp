#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> par(n);
        for (int i = 1; i < n; i++) {
            cin >> par[i];
            par[i]--;
        }
        int lo = 0, hi = n;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            vector<int> dp(n);
            int req = 0;
            for (int i = n - 1; i >= 1; i--) {
                if (par[i] != 0 && dp[i] + 1 >= mid) {
                    req++;
                } else {
                    dp[par[i]] = max(dp[par[i]], dp[i] + 1);
                }
            }
            (req <= k ? hi : lo) = mid;
        }
        cout << hi << '\n';
    }
}