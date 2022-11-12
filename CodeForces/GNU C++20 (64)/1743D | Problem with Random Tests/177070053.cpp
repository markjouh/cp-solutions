#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
// the solution to this problem basically relies on:
// we can just try prefixes, since removing characters from the front never helps us
// the first block of 0's (discluding leading zeroes) must overlap with the first block of 1's
// the probability of having a very large block of 0's or 1's is very small, so trying the first ~100
// shifts will almost definitely pass.
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    vector<bool> ans(n);
    for (int i = 0; i < 100; i++) {
        vector<bool> cur = a;
        for (int j = 0; j < n; j++) {
            if (j - i >= 0) {
                cur[j] = a[j] | a[j - i];
            }
        }
        for (int j = 0; j < n; j++) {
            if (cur[j] != ans[j]) {
                if (cur[j] > ans[j]) {
                    ans = cur;
                }
                break;
            }
        }
    }
    int bg = 0;
    while (bg + 1 < n && ans[bg] == 0) {
        bg++;
    }
    for (int i = bg; i < n; i++) {
        cout << ans[i];
    }
    cout << '\n';
}