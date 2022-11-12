#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double db;
 
#define fi first
#define se second
 
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define F0R(i, a) FOR(i, 0, a)
#define REP(a) F0R(_, a)
#define ROF(i, a, b) for (int i = b - 1; i >= (int)a; i--)
#define R0F(i, a) ROF(i, 0, a)
#define EACH(a, b) for (auto &a : b)
 
void run() {
  int n;
  cin >> n;
  vector<int> a(n);
  F0R(i, n) {
    cin >> a[i];
  }
  bool ok = true;
  FOR(i, 1, n) {
    ok &= a[i] % a[0] == 0;
  }
  cout << (ok ? "YES\n" : "NO\n");
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    run();
  }
}