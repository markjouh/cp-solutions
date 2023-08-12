#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

void solve() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<vector<int>> pref(h + 1, vector<int>(w + 1));
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    pref[r][c]++;
  }

  ll ans = 0;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      pref[i][j] += pref[i - 1][j];
      pref[i][j] += pref[i][j - 1];
      pref[i][j] -= pref[i - 1][j - 1];

      int lo = 0, hi = min(i, j) + 1;
      while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        (pref[i][j] - pref[i - mid][j] - pref[i][j - mid] + pref[i - mid][j - mid] == 0 ? lo : hi) = mid;
      }

      ans += lo;
    }
  }

  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  /* cin >> t; */
  while (t--) {
    solve();
  }
  return 0;
}


