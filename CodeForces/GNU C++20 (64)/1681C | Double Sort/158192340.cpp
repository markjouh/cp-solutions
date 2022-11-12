#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) {
      cin >> x;
    }
    for (int &x : b) {
      cin >> x;
    }
 
    set<int> st(a.begin(), a.end());
    vector<int> cmp(n + 1);
    int cnt = 0;
    for (int x : st) {
      cmp[x] = cnt++;
    }
    vector<pair<int, int>> b2(n);
    for (int i = 0; i < n; i++) {
      b2[i] = {cmp[a[i]], b[i]};
    }
    sort(b2.begin(), b2.end());
    bool sorted = true;
    for (int i = 1; i < n; i++) {
      sorted &= b2[i].second >= b2[i - 1].second;
    }
 
    if (!sorted) {
      cout << -1 << '\n';
      continue;
    }
 
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j] || b[i] > b[j]) {
          res.push_back({i, j});
          swap(a[i], a[j]);
          swap(b[i], b[j]);
        }
      }
    }
 
    cout << res.size() << '\n';
    for (auto [f, s] : res) {
      cout << f + 1 << ' ' << s + 1 << '\n';
    }
  }
}