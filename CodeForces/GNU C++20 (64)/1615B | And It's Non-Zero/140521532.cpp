#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully!
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 
 vector<vector<int>> occur(2e5+1, vector<int>(18));
 for (int i = 1; i <= 2e5+1; i++) {
  occur[i] = occur[i - 1];
  for (int j = 0; j < 18; j++) {
   occur[i][j] += (i >> j) & 1;
  }
 }
 
 int tc;
 cin >> tc;
 while (tc--) {
  int l, r;
  cin >> l >> r;
 
  vector<int> bits = occur[r];
  for (int i = 0; i < 18; i++) {
   bits[i] -= occur[l-1][i];
  }
 
  int ans = 1e9;
  for (int x : bits) {
   ans = min(ans, r-l+1-x);
  }
  cout << ans << '\n';
 }
}