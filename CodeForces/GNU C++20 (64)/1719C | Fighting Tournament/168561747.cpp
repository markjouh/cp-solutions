#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
// the number of wins fighter i gets is the the distance to the next greater fighter - 1.
// once fighter n gets to the front, they will never lose.
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> win(n, {1e9, -1e9});
        int pt = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[pt]) {
                pt = i;
            }
            win[pt].first = min(win[pt].first, i);
            win[pt].second = max(win[pt].second, i);
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == n) {
                win[i].second = 1e9;
            }
        }
        for (int i = 0; i < q; i++) {
            int idx, k;
            cin >> idx >> k;
            idx--;
            int l = max(win[idx].first, 1);
            int r = min(win[idx].second, k);
            cout << max(0, r - l + 1) << '\n';
        }
    }
}