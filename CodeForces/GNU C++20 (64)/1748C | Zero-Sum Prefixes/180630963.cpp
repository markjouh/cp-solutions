#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
 
// solve segments separately
// each segment starts at a 0, and ends before the next 0 (or the end of the array)
// for each segment, add increment the current prefix sum as a key in a map, and take the max value at the end
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                b.push_back(i);
            }
        }
        b.push_back(n);
        int ans = 0;
        if (!b.empty()) {
            ll pref = 0;
            for (int i = 0; i < b[0]; i++) {
                pref += a[i];
                if (pref == 0) {
                    ans++;
                }
            }
        }
        for (int i = 0; i < sz(b) - 1; i++) {
            ll pref = 0;
            map<ll, int> mp;
            for (int j = b[i]; j < b[i + 1]; j++) {
                pref += a[j];
                mp[pref]++;
            }
            int mx = 0;
            for (auto [f, s] : mp) {
                mx = max(mx, s);
            }
            ans += mx;
        }
        cout << ans << '\n';
    }
}