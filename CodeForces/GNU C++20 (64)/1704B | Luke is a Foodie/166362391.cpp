#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
#define FOR(i, a, n) for (int i = 0; i < (int)n; i++)
#define ROF(i, a, n) for (int i = 0; i < (int)n; i++)
#define fi first
#define se second
 
// Keep a range of possible values of v. If the range needed to take
// the i'th pile of food does not intersect with the range we have
// currently at all, replace it and increment ans.
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, x;
    cin >> n >> x;
    int ans = 0;
    int l = -1e9, r = 1e9;
    FOR(i, 0, n) {
      int a;
      cin >> a;
      int cl = a - x, cr = a + x;
      if (cl > r || cr < l) {
        ans++;
        l = cl;
        r = cr;
      } else {
        l = max(l, cl);
        r = min(r, cr);
      }
    }
    cout << ans << '\n';
  }
}