#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
// if k is odd, it's always possible, just add k to all odd numbers and any pairing should work.
// if k is even, we can try to form n / 2 multiples of 4.
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        if (k % 2) {
            cout << "YES\n";
            for (int i = 1; i <= n; i += 2) {
                cout << i << ' ' << i + 1 << '\n';
            }
        } else {
            vector<int> mul, k_mul;
            vector<bool> is_mul(n + 1);
            for (int i = 1; i <= n; i++) {
                if (i % 4 == 0) {
                    mul.push_back(i);
                    is_mul[i] = true;
                } else if ((i + k) % 4 == 0) {
                    k_mul.push_back(i);
                    is_mul[i] = true;
                }
                if (sz(mul) + sz(k_mul) == n / 2) {
                    break;
                }
            }
            if (sz(mul) + sz(k_mul) == n / 2) {
                cout << "YES\n";
                for (int i = 1; i <= n; i++) {
                    if (!is_mul[i]) {
                        if (sz(mul)) {
                            cout << i << ' ' << mul.back() << '\n';
                            mul.pop_back();
                        } else {
                            cout << k_mul.back() << ' ' << i << '\n';
                            k_mul.pop_back();
                        }
                    }
                }
            } else {
                cout << "NO\n";
            }
        }
    }
}