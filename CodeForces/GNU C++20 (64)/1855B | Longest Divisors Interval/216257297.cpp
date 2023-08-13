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
 
// the answer should be its minimal missing prime factor - 1
 
void solve() {
  ll n = get<ll>();
  for (int i = 2; i <= 1000; i++) {
    if (n % i) {
      cout << i - 1 << '\n';
      return;
    }
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