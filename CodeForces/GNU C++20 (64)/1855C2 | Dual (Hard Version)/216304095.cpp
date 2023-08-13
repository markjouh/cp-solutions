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
 
// for the hard version: I feel like we can use a similar strat
// look at the side (pos or neg) with the highest abs element
// this side can always take over, unless the opposing side has 13+ elements
// if one side has 13+ elements, it can stack itself 5 times, then take over
// thus one side can always take over this way
 
// I think my wa before was bc I wasn't trying both sides at once
 
void solve() {
  int n = nxt();
  vector<ll> a(n);
  generate(all(a), nxt);
 
  int mn_p = min_element(all(a)) - a.begin();
  int mx_p = max_element(all(a)) - a.begin();
 
  vector<pii> ans;
 
  for (int i = 0; i <= 31; i++) { // times to stack mn
    vector<ll> b = a;
    vector<pii> cur;
    for (int j = 0; j < i; j++) {
      cur.push_back({mn_p, mn_p});
      b[mn_p] += b[mn_p];
    }
    for (int j = 0; j < n; j++) {
      if (b[j] > 0) {
        cur.push_back({j, mn_p});
        b[j] += b[mn_p];
      }
    }
    for (int j = n - 2; j >= 0; j--) {
      if (b[j] > b[j + 1]) {
        cur.push_back({j, j + 1});
        b[j] += b[j + 1];
      }
    }
    bool asc = true;
    for (int j = 1; j < n; j++) {
      asc &= b[j] >= b[j - 1];
    }
    if (asc && sz(cur) <= 31) {
      ans = cur;
      break;
    }
  }
 
  for (int i = 0; i <= 31; i++) { // times to stack mx
    vector<ll> b = a;
    vector<pii> cur;
    for (int j = 0; j < i; j++) {
      cur.push_back({mx_p, mx_p});
      b[mx_p] += b[mx_p];
    }
    for (int j = 0; j < n; j++) {
      if (b[j] < 0) {
        cur.push_back({j, mx_p});
        b[j] += b[mx_p];
      }
    }
    for (int j = 1; j < n; j++) {
      if (b[j] < b[j - 1]) {
        cur.push_back({j, j - 1});
        b[j] += b[j - 1];
      }
    }
    bool asc = true;
    for (int j = 1; j < n; j++) {
      asc &= b[j] >= b[j - 1];
    }
    if (asc && sz(cur) <= 31) {
      ans = cur;
      break;
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