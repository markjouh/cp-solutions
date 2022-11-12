#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
 
const int MOD = 1e9 + 7;
const int B = 9973;
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pow_b(n + 1, 1);
    for (int i = 0; i < n; i++) {
        pow_b[i + 1] = pow_b[i] * B % MOD;
    }
    vector<int> h(n + 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * B + s[i]) % MOD;
    }
 
    auto get_hash = [&](int l, int r) {
        return ((h[r] - h[l] * pow_b[r - l] % MOD) + MOD) % MOD;
    };
 
    int lo = 0, hi = n + 1;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        bool flag = false;
        for (int i = 1; i + mid < n; i++) {
            if (get_hash(0, mid) == get_hash(i, i + mid)) {
                flag = true;
                break;
            }
        }
        (flag ? lo : hi) = mid;
    }
    while (get_hash(0, lo) != get_hash(n - lo, n)) {
        lo--;
    }
    cout << (lo == 0 ? "Just a legend" : s.substr(0, lo));
}