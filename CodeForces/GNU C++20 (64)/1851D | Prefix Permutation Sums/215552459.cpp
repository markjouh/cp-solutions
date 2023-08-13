#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
 int n;
 cin >> n;
 vector<bool> have(n + 1);
 vector<ll> over;
 ll prev = 0;
 ll k = -1;
 for (int i = 0; i < n - 1; i++) {
  ll x;
  cin >> x;
  ll diff = x - prev;
  if (diff > n || (diff <= n && have[diff])) {
   k = diff;
  } else {
   have[diff] = true;
  }
  prev = x;
 }
 int miss = 0;
 ll tot = 0;
 for (int i = 1; i <= n; i++) {
  if (!have[i]) {
   miss++;
   tot += i;
  }
 }
 // cout << miss << ' ' << tot << '\n';
 cout << (miss == 1 || (miss == 2 && k == tot) ? "YES\n" : "NO\n");
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