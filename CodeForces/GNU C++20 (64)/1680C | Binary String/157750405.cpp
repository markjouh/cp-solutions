#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    vector<int> pos;
    for (int i = 0; i < sz(s); i++) {
      if (s[i] == '1') {
        pos.push_back(i);
      }
    }
    int lo = -1, hi = sz(pos);
    while (lo + 1 < hi) {
      // The answer we are currently trying to achieve.
      int mid = lo + (hi - lo) / 2;
 
      // We want to have exactly (keep) 1's.
      int keep = sz(pos) - mid;
 
      if (keep < 2) {
        (sz(pos) - keep <= mid ? hi : lo) = mid;
        continue;
      }
 
      // Otherwise, we try all subarrays with (keep) 1's and no leading or trailing 0's, and check if the # of 0's in it are <= mid
      bool ok = false;
      for (int i = 0; i + keep - 1 < sz(pos); i++) {
        ok |= pos[i + keep - 1] - pos[i] + 1 - keep <= mid;
      }
      (ok ? hi : lo) = mid;
    }
    cout << hi << '\n';
  }
}