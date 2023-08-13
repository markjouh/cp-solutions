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
 
// calculate the parity of the number of times each character appears for each string, call this its parity profile
// for two strings a and b to form a nightmare, b must be the complement of a, with one exception
// there must be exactly one character which both of them are missing
 
// we can just iterate over all strings, fixing the empty element and counting pairs w/passed strings
 
// I came up with all this during the contest, but forgot about using map for the frequency array and thought I'd get MLE :(
 
void solve() {
  int n = nxt();
 
  map<int, array<int, 26>> mp; // [parity profile][missing char] = count
  ll ans = 0;
 
  while (n--) {
    vector<bool> has(26), par(26);
    for (char c : get<string>()) {
      c -= 'a';
      has[c] = true;
      par[c] = par[c] ^ 1;
    }
    int p = 0;
    for (int i = 0; i < 26; i++) {
      if (par[i]) {
        p |= 1 << i;
      }
    }
    int cmp = ((1 << 26) - 1) ^ p;
    for (int i = 0; i < 26; i++) {
      if (!has[i]) {
        cmp ^= 1 << i;
 
        if (mp.count(cmp)) {
          ans += mp[cmp][i];
        }
 
        cmp ^= 1 << i;
      }
    }
    if (!mp.count(p)) {
      array<int, 26> ar;
      fill(all(ar), 0);
      mp.insert({p, ar});
    }
    for (int i = 0; i < 26; i++) {
      if (!has[i]) {
        mp[p][i]++;
      }
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