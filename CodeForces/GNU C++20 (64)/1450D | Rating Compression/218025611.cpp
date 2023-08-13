#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
typedef long long ll;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
void solve() {
    int n;
    cin >> n;
    deque<int> a(n);
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
 
    vector<bool> ans(n);
    ans[0] = *min_element(freq.begin() + 1, freq.end()) == 1;
    for (int i = n - 1; i >= 1; i--) {
        const int cur = n - i, prev = cur - 1;
 
        bool ok = true;
        ok &= freq[cur] >= 1;
 
        if (prev != 0) {
            ok &= freq[prev] == 1 && (a.front() == prev || a.back() == prev);
            if (a.front() == prev) a.pop_front();
            if (a.back() == prev) a.pop_back();
        }
 
        if (ok) {
            ans[i] = true;
        } else {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << '\n';
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
 
Let the number of segments be n - k + 1.
For segments = 1, just check whether the string is a permutation
For segments > 1, numbers < K must be on the sides and appear exactly once, while (segments) must appear at least once anywhere else
 
We should be able to implement this efficiently using a frequency array and deque.
 
*/