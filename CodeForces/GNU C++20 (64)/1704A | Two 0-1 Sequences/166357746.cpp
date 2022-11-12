#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
#define FOR(i, a, n) for (int i = 0; i < (int)(n); i++)
#define ROF(i, a, n) for (int i = 0; i < (int)(n); i++)
#define fi first
#define se second
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    bool ok1 = true;
    FOR(i, 0, b.size() - 1) {
      ok1 &= a[n - i - 1] == b[m - i - 1];
    }
    bool ok2 = false;
    FOR(i, 0, n - b.size() + 1) {
      ok2 |= a[i] == b[0];
    }
    // cout << n - b.size() + 1 << '\n';
    // cout << ok1 << ' ' << ok2 << '\n';
    cout << (ok1 && ok2 ? "YES\n" : "NO\n");
  }
}