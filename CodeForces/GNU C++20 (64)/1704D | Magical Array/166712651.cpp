#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> c(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    cin >> c[i][j];
    if (j > 0) {
     c[i][j] += c[i][j - 1];
    }
   }
  }
  vector<ll> sum(n);
  for (int i = 0; i < n; i++) {
   sum[i] = accumulate(all(c[i]), 0ll);
  }
  int k = -1, op = 0;
  for (int i = 0; i < n; i++) {
   int same = 0, diff = 0;
   for (int j = 0; j < n; j++) {
    if (i == j) {
     continue;
    }
    same += sum[i] == sum[j];
    diff += sum[i] != sum[j];
    if (same == 2) {
     break;
    }
    if (diff == 2) {
     k = i;
     op = sum[j] - sum[i];
     break;
    }
   }
  }
  cout << k + 1 << ' ' << op << '\n';
 }
}