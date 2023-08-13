// trying to get the fastest submission lol
 
#include <bits/stdc++.h>
 
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
using ll = long long;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
void solve() {
    string s;
    cin >> s;
    vector<int> prev(26, -1), mx_seg(26);
    for (int i = 0; i < sz(s); i++) {
        int c = s[i] - 'a';
        mx_seg[c] = max(mx_seg[c], i - prev[c] - 1);
        prev[c] = i;
    }
    for (int i = 0; i < 26; i++) {
        mx_seg[i] = max(mx_seg[i], sz(s) - prev[i] - 1);
    }
 
    int mx_lz = 0;
    for (int i = 0; i < 26; i++) {
        if (mx_seg[i] == 0) {
            cout << 0 << '\n';
            return;
        }
        mx_lz = max(mx_lz, __builtin_clz(mx_seg[i]));
    }
    cout << 32 - mx_lz << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
 
/*
the string needs to contain at most one distinct character, so let's fix this character c
all characters not equal to c must be erased, and no occurrences of c need to be erased (doing so can't decrease the answer)
look at the separate chunks of ones not equal to c
since they are divided by c's, any operation used in one chunk can be extended to another
so we just need to solve for all chunks separately and find the max
*/