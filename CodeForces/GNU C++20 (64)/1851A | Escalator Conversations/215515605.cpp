#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
 int n, m, k, h;
 cin >> n >> m >> k >> h;
 
 int ans = 0;
 for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
  if (x != h && abs(x - h) % k == 0 && abs(x - h) / k < m) {
   ans++;
  }
 }
 
 cout << ans << '\n';
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