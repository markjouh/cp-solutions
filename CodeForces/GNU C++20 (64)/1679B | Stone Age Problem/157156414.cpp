#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rep1(i, n) for (int i = 1; i <= int(n); i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  int n, q;
  cin >> n >> q;
  ll sum = 0, lastupd = -1, updval = 0;
  vector<int> a(n), upd(n);
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  rep1(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int id, x;
      cin >> id >> x;
      id--;
      if (upd[id] < lastupd) {
        a[id] = updval;
      }
      sum += x - a[id];
      a[id] = x;
      upd[id] = i;
    } else {
      int x;
      cin >> x;
      sum = 1ll * n * x;
      lastupd = i;
      updval = x;
    }
    cout << sum << '\n';
  }
}