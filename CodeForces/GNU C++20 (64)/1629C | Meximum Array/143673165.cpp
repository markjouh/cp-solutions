#include <bits/stdc++.h>
using namespace std;
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    int last = 1e9, st = 0;
    vector<int> res;
    while (st < n) {
      int mex = 0, id = st;
      vector<bool> has(n + 2);
      for (int i = st; i < n; i++) {
        has[a[i]] = true;
        if (has[mex]) {
          id = i;
        }
        while (has[mex]) {
          mex++;
        }
        if (mex == last) {
          break;
        }
      }
      res.push_back(mex);
      last = mex;
      st = id + 1;
    }
    cout << res.size() << '\n';
    for (int x : res) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}