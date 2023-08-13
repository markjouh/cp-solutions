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
  
  vector<int> d;
  while (n > 0) {
    d.push_back(n % 10);    
    n /= 10;
  }
 
  int dp[11][2][2]; // digits completed, carry to i+1, carry to i+2 = ways
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
 
  for (int i = 0; i < sz(d); i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int a = 0; a < 10; a++) {
          for (int b = 0; b < 10; b++) {
            if ((a + b + j) % 10 == d[i]) {
              dp[i + 1][k][(a + b + j) / 10] += dp[i][j][k];
            }
          }
        }
      }
    }
  }
 
  cout << dp[sz(d)][0][0] - 2 << '\n';
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
 
 