#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
// cram the best (very low, very high) values into the corner (0, 0), (0, 1), (1, 0)
// just bruteforce 3 of them
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  vi a(n * m);
  rep(i, 0, n * m) {
   cin >> a[i];
  }
  sort(all(a));
  vi t;
  rep(i, 0, min(3, sz(a))) {
   t.push_back(a[i]);
   t.push_back(a[n * m - i - 1]);
  }
  int ans = 0;
  rep(i, 0, sz(t)) {
   rep(j, 0, sz(t)) {
    rep(k, 0, sz(t)) {
     if (i != j && j != k) {
      int cur = 0;
      cur += abs(t[i] - t[j]) * (n - 1);
      cur += abs(t[i] - t[k]) * (m - 1);
      cur += max({abs(t[i] - t[j]), abs(t[i] - t[k]), abs(t[j] - t[k])}) * (n - 1) * (m - 1);
      ans = max(ans, cur);
     }
    }
   }
  }
  cout << ans << '\n';
 }
}