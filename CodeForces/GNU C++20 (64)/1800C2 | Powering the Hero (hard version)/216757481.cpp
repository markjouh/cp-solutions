#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
 
#define all(x) begin(x), end(x)
#define sz(x) static_cast<int>(size(x))
 
template<typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
 
template<typename T> bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
 
template<typename T> bool ckmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}
 
template<typename T> T get() {
  T x;
  cin >> x;
  return x;
}
 
int nxt() {
  return get<int>();
}
 
// --------------------------------
 
void solve() {
  int n = nxt();
  priority_queue<int> pq;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int x = nxt();
    pq.push(x);
    if (x == 0) {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << '\n';
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