#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, x;
        cin >> n >> x;
        vector<int> h(n * 2);
        for (int i = 0; i < n * 2; i++) {
            cin >> h[i];
        }
        sort(all(h));
        bool ok = true;
        for (int i = 0; i < n; i++) {
            ok &= h[i] + x <= h[i + n];
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}