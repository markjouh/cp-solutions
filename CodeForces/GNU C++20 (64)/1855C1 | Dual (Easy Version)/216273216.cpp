#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
 
#define all(x) begin(x), end(x)
#define sz(x) static_cast<int>(size(x))
 
template<class T> bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
 
template<class T> bool ckmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}
 
template<class T> T get() {
  T x;
  cin >> x;
  return x;
}
 
int nxt() {
  return get<int>();
}
 
// --------------------------------
 
// if the array is all positive, we can solve it trivially by going left to right
// and adding a[i - 1] to a[i] whenever a[i - 1] > a[i]
// we can do smth similar for all negatives, just in reverse
 
// for the easy version, I think we can just rely on these two cases
// pick the side with the greater absolute value, make everything neg/pos, then apply above
 
// for the hard version: idk yet
 
void solve() {
  int n = nxt();
  vector<int> a(n);
  generate(all(a), nxt);
 
  int mn_p = min_element(all(a)) - a.begin();
  int mx_p = max_element(all(a)) - a.begin();
 
  vector<pii> ans;
  if (abs(a[mn_p]) > a[mx_p]) {
    for (int i = 0; i < n; i++) {
      ans.push_back({i, mn_p});
      a[i] += a[mn_p];
    }
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > a[i + 1]) {
        ans.push_back({i, i + 1});
        a[i] += a[i + 1];
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      ans.push_back({i, mx_p});
      a[i] += a[mx_p];
    }
    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) {
        ans.push_back({i, i - 1});
        a[i] += a[i - 1];
      }
    }
  }
  cout << sz(ans) << '\n';
  for (auto [f, s] : ans) {
    cout << f + 1 << ' ' << s + 1 << '\n';
  }
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = nxt();
  while (t--) {
    solve();
  }
  return 0;
}