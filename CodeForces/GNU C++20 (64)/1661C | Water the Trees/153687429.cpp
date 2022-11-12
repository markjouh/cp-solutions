#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, b) for (auto &a : b)
#define rep(a) FOR(_, 0, a)
 
using namespace std;
 
long long cost(vector<int> h, int tgt) {
  long long l = -1, r = 3e14;
  while (l + 1 < r) {
    long long mid = midpoint(l, r);
    long long ones = (mid + 1) / 2, twos = mid / 2;
    each(x, h) {
      long long add = tgt - x;
      long long mn = min(add / 2, twos);
      add -= mn * 2;
      twos -= mn;
      ones -= add;
    }
    (ones >= 0 ? r : l) = mid;
  }
  return r;
}
 
void solve() {
  int n;
  cin >> n;
  vector<int> h(n);
  each(x, h) {
    cin >> x;
  }
  int mx = *max_element(all(h));
  /*
    For an integer x >= mx, if making all numbers = x + 2 is possible, making them equal to x is as well.
    This is because the +2 can be formed out of 2 1's or 1 2. Since one of these will always be in each element's
    composition, it is always possible to decrease each element by 2. Because of this, checking mx is sufficient
    for all numbers with the same parity after it as well (and will take less operations to get to).
  
    However, this does not hold true for x + 1. This is because a 1 must be included in the composition of each
    element for it to be possible to decrease each by 1, which is not always true. However, checking it will be
    sufficient for all numbers with the same parity after it due to the observation above.
  */
  cout << min(cost(h, mx), cost(h, mx + 1)) << '\n';
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  rep(tc) {
    solve();
  }
}