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
 vector<int> c(n);
 for (int i = 0; i < n; i++) {
  cin >> c[i];
 }
 int cur = 0;
 for (int i = 0; i < n; i++) {
  if (cur < k) {
   cur += c[i] == c[0];
  } else {
   cur += c[i] == c[n - 1];
  }
 }
 cout << ((c[0] == c[n - 1] && cur >= k) || cur >= 2 * k ? "YES\n" : "NO\n");
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