#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<set<int>> has(n+1);
    FOR(i, n) {
      int x;
      cin >> x;
      while (x > 0) {
        if (x <= n) {
          has[x].insert(i);
        }
        x /= 2;
      }
    }
    // {size, index}
    vector<pair<int, int>> vals;
    FOR(i, n) {
      vals.push_back({has[i+1].size(), i+1});
    }
    sort(vals.begin(), vals.end());
    bool ok = true;
    for (auto [f, s] : vals) {
      if (has[s].empty()) {
        ok = false;
        break;
      }
      int bg = *has[s].begin();
      FOR(j, n) {
        has[j+1].erase(bg);
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/