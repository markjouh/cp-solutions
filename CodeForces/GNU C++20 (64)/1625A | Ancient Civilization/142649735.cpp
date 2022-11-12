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
    int n, m;
    cin >> n >> m;
    vector<int> ct(m);
    FOR(i, n) {
      int x;
      cin >> x;
      FOR(j, m) {
        ct[j] += (x>>j)&1;
      }
    }
    int ans = 0;
    FOR(i, m) {
      if (n-ct[i] < ct[i]) {
        ans += (1<<i);
      }
    }
    cout << ans << '\n';
    // FOR(i, m) {
    //   cout << ct[i] << " \n"[i==m-1];
    // }
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/