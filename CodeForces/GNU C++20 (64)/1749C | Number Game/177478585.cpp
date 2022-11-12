#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
// whenever bob applies the operation to an element, alice can no longer take it (at any point forward)
// bob will always win eventually, and alice can only win if k runs out before there are no more elements
// k must be <= n
// just write (n^2)
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));
 
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            int k = n;
            int l = 0;
            bool ok = true;
            for (int j = 0; j < i; j++) {
                k--;
                while (k >= 0 && a[k] > i - j) {
                    k--;
                }
                if (k < l) {
                    ok = false;
                    break;
                }
                l++;
            }
            if (ok) {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
}