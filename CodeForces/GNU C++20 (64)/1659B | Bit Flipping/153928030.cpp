#include <bits/stdc++.h>
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= a; i--)
#define each(a, b) for (auto &a : b)
#define rep(a) FOR(_, 0, a)
 
using namespace std;
 
void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  
  vector<int> bits(n), res(n);
  FOR(i, 0, n - 1) {
    bits[i] = (s[i] - '0' + k) % 2;
  }
  bits[n - 1] = s[n - 1] - '0';
  res[n - 1] = k;
  
  FOR(i, 0, n - 1) {
    if (bits[i] == 0 && res[n - 1] > 0) {
      bits[i] ^= 1;
      bits[n - 1] ^= 1;
      res[i]++;
      res[n - 1]--;
    }
  }
  
  each(x, bits) {
    cout << x;
  }
  cout << '\n';
  each(x, res) {
    cout << x << ' ';
  }
  cout << '\n';
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  rep(tc) {
    solve();
  }
}