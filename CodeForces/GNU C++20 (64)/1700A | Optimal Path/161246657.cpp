#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define REP(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = b - 1; i >= (int)a; i--)
#define PER(i, a) ROF(i, 0, a)
 
template<class T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    REP(i, m) {
      ans += i;
    }
    FOR(i, 1, n + 1) {
      ans += m * i;
    }
    cout << ans << '\n';
  }
}