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
        int n, m;
        cin >> n >> m;
        vector<bool> r(n), c(n);
        while (m--) {
            int c_r, c_c;
            cin >> c_r >> c_c;
            c_r--;
            c_c--;
            r[c_r] = true;
            c[c_c] = true;
        }
        bool ans = false;
        for (int i = 0; i < n; i++) {
            ans |= !r[i];
            ans |= !c[i];
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}