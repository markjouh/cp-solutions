// mzh
 
/*
Informal proof (just to review):
 
(The first part of this is just the same as the editorial: "NO" if (n + m) % 2 == 0, represent the paths as a string of R's and D's, swap adjacent characters to get a difference of 2. The rest of it is also mostly the same, just in slightly different words)
 
Since it is possible to create any ordering just by swapping adjacent elements, it is possible to turn the path with minimum sum into the path with maximum sum just by swapping adjacent moves in our path.
 
Next, since we are only performing adjacent swap operations, the total sum of the path won't change by more than 2 at once.
 
Since these two things above are true, there must exist a path where sum == x for all even x in the range [mn...mx]. Because we are asked to find 0 in this problem, we can just check if mn <= 0 <= mx.
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mn(n, vector<int>(m, 1e9));
    vector<vector<int>> mx(n, vector<int>(m, -1e9));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        if (i == 0 && j == 0) {
          mn[i][j] = x;
          mx[i][j] = x;
        }
        if (i > 0) {
          mn[i][j] = min(mn[i][j], mn[i - 1][j] + x);
          mx[i][j] = max(mx[i][j], mx[i - 1][j] + x);
        }
        if (j > 0) {
          mn[i][j] = min(mn[i][j], mn[i][j - 1] + x);
          mx[i][j] = max(mx[i][j], mx[i][j - 1] + x);
        }
      }
    }
    if ((n + m) % 2 == 0) {
      cout << "NO\n";
      continue;
    }
    cerr << mn[n - 1][m - 1];
    cout << (mn[n - 1][m - 1] <= 0 && 0 <= mx[n - 1][m - 1] ? "YES\n" : "NO\n");
  }
}