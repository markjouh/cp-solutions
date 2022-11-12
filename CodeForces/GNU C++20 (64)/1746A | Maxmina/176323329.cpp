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
        bool ok = false;
        for (int i = 0; i < n; i++) {
            bool b;
            cin >> b;
            ok |= b;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}