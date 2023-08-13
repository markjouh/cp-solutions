#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
// if n % m == 0, the starting state can stay forever
// otherwise, some options are always eliminated
// maybe check if there exists x where 1 < x <= m and n % x == 0
 
// to reach a state where m > 1 and no options are eliminated (the conditions of going infinite), the number of
// active algorithm choices should be a factor of the number of people
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  bool ok = false;
  for (ll i = 1; i * i <= n; i++) {
   if (n % i == 0) {
    ok |= i > 1 && i <= m;
    ok |= n / i > 1 && n / i <= m;
   }
  }
  cout << (ok ? "NO\n" : "YES\n");
 }
}