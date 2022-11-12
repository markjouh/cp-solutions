#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
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
        if (n == 3) {
            cout << "1 2 3\n";
            continue;
        }
        int m = n / 2 * 2;
        vector<int> a(n), cnt = {1, 1};
        for (int i = 0; i < m; i++) {
            a[i] = cnt[i % 2]++;
            if (i % 2 == 0) {
                a[i] += 1 << 29;
            } else {
                a[i] += 1 << 30;
            }
        }
 
        if (m / 2 % 2) {
            a[0] -= 1 << 29;
            a[m - 1] -= 1 << 30;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
 
        // DEBUG
        int xor_e = 0;
        int xor_o = 0;
        for (int i = 0; i < n; i++) {
            (i % 2 ? xor_o : xor_e) ^= a[i];
        }
        cerr << xor_e << ' ' << xor_o << '\n';
    }
}