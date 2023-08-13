#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
 
void solve() {
  int n, k;
  cin >> n >> k;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % k != 0) {
      mp[x % k].push_back(i);
    } else {
      cout << i + 1 << ' ';
    }
  }
  vector<vector<int>> r;
  for (auto [k, v] : mp) {
    r.push_back(v);
  }
  for (int i = sz(r) - 1; i >= 0; i--) {
    for (int x : r[i]) {
      cout << x + 1 << ' ';
    }
  }
  cout << '\n';
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