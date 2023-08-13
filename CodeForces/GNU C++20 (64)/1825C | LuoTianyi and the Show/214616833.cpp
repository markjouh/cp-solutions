#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
// fix a center and build on it
// or, we can alternatively build with the option of starting with some type, but this will disable us from using the other
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  int from_l = 0, from_r = 0;
  vi seen(m), fixed;
  rep(i, 0, n) {
   int x;
   cin >> x;
   if (x < 0) {
    (x == -1 ? from_l : from_r)++;
   } else if (!seen[x-1]) {
    seen[x-1] = true;
    fixed.push_back(x);
   }
  }
  sort(all(fixed));
  int ans = 0;
  rep(i, 0, sz(fixed)) {
   int left = i+1 + min(from_l, fixed[i]-i-1);
   int right = sz(fixed)-i-1 + min(from_r, m-fixed[i] - (sz(fixed)-i-1));
   ans = max(ans, left + right);
  }
  ans = max(ans, sz(fixed) + from_l);
  ans = max(ans, sz(fixed) + from_r);
  ans = min(ans, m);
  cout << ans << '\n';
 }
}