#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(all(a));
  int idx = 0;
  for (int i = 0; i < n - 1; i++) {
    if ((a[i].first ^ a[i + 1].first) < (a[idx].first ^ a[idx + 1].first)) {
      idx = i;
    }
  }
  // cout << (a[idx].first ^ a[idx + 1].first) << '\n';
  cout << a[idx].second + 1 << ' ' << a[idx + 1].second + 1 << ' ' << ((a[idx].first | a[idx + 1].first) ^ ((1 << k) - 1)) << '\n';
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}