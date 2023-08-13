#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
 
  int best_a = 0, best_b = 0, ans = 0;
 
  rep(i, 0, n) {
   int x;
   cin >> x;
   // use i as a third point, pair with a pair from the prefix [0..i)
   ans = max(ans, best_b - i + x);
 
   // use i as a second point, pair with a point from the prefix [0..i) and store
   best_b = max(best_b, best_a + x);
 
   // store i as a lone point to be paired (add i to its value to prioritize closer points)
   best_a = max(best_a, x + i);
  }
 
  cout << ans << '\n';
 }
}