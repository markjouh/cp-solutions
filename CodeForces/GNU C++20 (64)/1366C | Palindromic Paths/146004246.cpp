#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define rb pop_back
#define bg begin()
#define ed end()
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  int diag = n + m - 1;
  vector<vector<int>> ct(diag, vector<int>(2));
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    bool b;
    cin >> b;
    ct[i + j][b]++;
   }
  }
  int ans = 0;
  for (int i = 0; i < diag / 2; i++) {
   ans += min(ct[i][0] + ct[diag - i - 1][0], ct[i][1] + ct[diag - i - 1][1]);
  }
  cout << ans << '\n';
 }
}