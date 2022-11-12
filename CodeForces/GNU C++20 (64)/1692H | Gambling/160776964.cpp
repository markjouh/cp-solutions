#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define REP(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = b - 1; i >= (int)a; i--)
#define PER(i, a) ROF(i, 0, a)
 
int kadane(vector<int> a) {
  int best = 0, cur = 0;
  REP(i, a.size()) {
    cur = max(0, cur + a[i]);
    best = max(best, cur);
  }
  return best;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    REP(i, n) {
      cin >> a[i];
      mp[a[i]].push_back(i);
    }
    int best_sum = 0, best_val = 0;
    for (auto [val, pos] : mp) {
      vector<int> occ;
      REP(i, pos.size() - 1) {
        occ.push_back(1);
        occ.push_back(-(pos[i + 1] - pos[i] - 1));
      }
      occ.push_back(1);
      int sum = kadane(occ);
      if (sum > best_sum) {
        best_sum = sum;
        best_val = val;
      }
    }
    int pref = 0;
    int l = 0, r = 0;
    map<int, int> seen;
    seen[0] = -1;
    REP(i, n) {
      pref += (a[i] == best_val ? 1 : -1);
      if (seen.count(pref - best_sum)) {
        l = seen[pref - best_sum] + 1;
        r = i;
        break;
      }
      seen[pref] = i;
    }
    cout << best_val << ' ' << l + 1 << ' ' << r + 1 << '\n';
  }
}