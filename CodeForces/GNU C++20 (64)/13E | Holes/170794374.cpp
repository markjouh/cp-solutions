#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> power(n);
    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }
    int len = sqrt(n);
    vector<int> next(n, -1), cnt(n);
    
    auto calc = [&](int l, int r) {
        for (int i = r - 1; i >= l; i--) {
            int j = i + power[i];
            if (j >= n) {
                next[i] = i;
                cnt[i] = 0;
            } else if (j / len > i / len) {
                next[i] = j;
                cnt[i] = 1;
            } else {
                next[i] = next[j];
                cnt[i] = 1 + cnt[j];
            }
        }
    };
 
    calc(0, n);
 
    while (q--) {
        int op, i;
        cin >> op >> i;
        i--;
        if (op) {
            int ans = 0;
            do {
                ans += cnt[i];
                i = next[i];
            } while (next[i] != i);
            cout << i + 1 << ' ' << ans + 1 << '\n';
        } else {
            cin >> power[i];
            calc(i / len * len, i + 1);
        }
    }
}