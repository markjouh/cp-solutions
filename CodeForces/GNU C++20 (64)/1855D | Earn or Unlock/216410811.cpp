#ifdef ONLINE_JUDGE
  #pragma GCC optimize("Ofast,no-stack-protector")
  #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
  #pragma GCC optimize("unroll-loops")
#endif
 
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
 
// if two cards i and j are unlocked, it doesn't matter which order we take them in,
// so just take from top first
 
// try dp
 
// dp(i)[j] = (current prefix of the deck)[unlocked cards] = max victory score
// suppose we're deciding the what we do with the i'th card from the top (1-ind)
// obviously we can't transition from states w/ unlocked < i
// for all states [i, n]:
// 1) ckmax dp[i + v], dp[i]
// 2) dp[i] += v
 
// ok, now for the bitset solution
// for a state that unlocks m cards, the value is pref[min(n, m)] - m + 1
// so, we don't actually need to store the value
// just compute a bitset of all reachable unlock values
 
constexpr int MXN = 2e5;
 
void solve() {
  int n = nxt();
  vector<int> a(n);
  generate(all(a), nxt);
 
  bitset<MXN> ok;
  ok[1] = 1;
  for (int i = 0; i < n; i++) {
    // for (int j = i + 1; j < n; j++) {
    //   b[j + a[i]] = b[j + a[i]] | ok[j];
    // }
    ok |= (ok >> (i + 1)) << (i + 1 + a[i]);
  }
  ll pref = 0, ans = 0;
  for (int i = 0; i + 1 < 2 * n; i++) {
    pref += i < n ? a[i] : 0;
    if (ok[i + 1]) {
      ckmax(ans, pref - i);
    }
  }
  cout << ans << '\n';
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1; // nxt();
  while (t--) {
    solve();
  }
  return 0;
}