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
        int n;
        cin >> n;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        bool ok = true;
        vector<int> res(n);
        res[0] = d[0];
        for (int i = 1; i < n; i++) {
            if (d[i] > 0 && res[i - 1] - d[i] >= 0) {
                ok = false;
                break;
            }
            res[i] = res[i - 1] + d[i];
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}