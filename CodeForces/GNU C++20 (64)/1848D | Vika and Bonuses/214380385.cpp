#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
// let X be the amount of cycles of 2, 4, 8, 6 to go through from some state (s, k)
 
// we want to maximize the total discount, represented by the following function f(x):
// (s + 20X) * (k - 4X)
// SK - 4SX + 20KX - 80X^2
// -80X^2 + (20K - 4S)X + SK
 
// the vertex V of the parabola is at -B / 2A
// V.x = (4S - 20K) / (-160)
 
// find, plug in, and ckmax the ceil and floor of this
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
 int tc;
 cin >> tc;
 while (tc--) {
  ll s, k;
  cin >> s >> k;
  ll ans = s * k;
  if (s % 10 == 5) {
   ans = max(ans, (s + 5) * (k - 1));
  } else if (s % 10) {
   if (s % 2) {
    s += s % 10;
    k--;
   }
   rep(i, 0, 4) {
    auto f = [&](ll x) -> ll {
     x = max(x, 0ll);
     return (s + 20 * x) * (k - 4 * x);
    };
    ans = max(ans, f((4 * s - 20 * k) / -160));
    ans = max(ans, f((4 * s - 20 * k - 159) / -160));
    s += s % 10;
    k--;
   }
  }
  cout << ans << '\n';
 }
}