#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(150001);
    FOR(i, n) {
      int x;
      cin >> x;
      a[x].push_back({i, n-i-1});
    }
    int ans = -1;
    FOR(i, 150001) {
      if (a[i].size() > 1) {
        int m = a[i].size();
        FOR(j, m-1) {
          ans = max(ans, a[i][j].first+1+min(a[i][j].second, a[i][j+1].second));
        }
      }
    }
    cout << ans << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/