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
 
void solve() {
  int n = nxt();
  int same = 0;
  for (int i = 1; i <= n; i++) {
    if (nxt() == i) {
      same++;
    }
  }
  cout << (same + 1) / 2 << '\n';
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