#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
 
// A diverse substring can be length 100 at most
// if it's length 101, there is 11 of some digit, which is > 10, the number of distinct digits
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = s[i] - '0';
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> cnt(10);
            int distinct = 0, mxcnt = 0;
            for (int j = i; j < min(n, i + 100); j++) {
                if (cnt[d[j]]++ == 0) {
                    distinct++;
                }
                mxcnt = max(mxcnt, cnt[d[j]]);
                if (mxcnt <= distinct) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}