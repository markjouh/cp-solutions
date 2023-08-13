#include "bits/stdc++.h"
using namespace std;
 
#ifdef ONLINE_JUDGE
#define debug if (false)
#else
#define debug if (true)
#endif
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j + 1 < n; j++) {
      if (a[j] == 2 && a[j + 1] == 1) {
        a[j + 1] = 2;
      }
    }
    reverse(all(a));
  }
  debug {
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  vector<pii> seg;
  int prev = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != prev) {
      seg.emplace_back(a[i], 0);
      prev = a[i];
    }
    seg.back().second++;
  }
  debug {
    for (auto [a, b] : seg) {
      cout << a << ' ' << b << '\n';
    }
  }
  for (int i = 0; i < sz(seg); i++) {
    if (seg[i].first == 2) {
      if (i > 0 && seg[i - 1].second > 0) {
        seg[i - 1].second--;
      }
      if (i + 1 < sz(seg) && seg[i + 1].second > 0) {
        seg[i + 1].second--;
      }
    }
  }
  for (int i = 0; i < sz(seg); i++) {
    if (seg[i].first == 1) {
      if (i > 0 && seg[i - 1].second > 0) {
        seg[i - 1].second--;
      } else if (i + 1 < sz(seg) && seg[i + 1].second > 0) {
        seg[i + 1].second--;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < sz(seg); i++) {
    ans += seg[i].first == 0 ? seg[i].second : 1;
  }
  cout << ans << '\n';
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}