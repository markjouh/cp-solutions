#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int ct = 0;
    while (x > 0) {
      mp[x].push_back(ct++);
      x /= 2;
    }
    mp[0].push_back(ct);
  }
  int ans = 1e9;
  for (auto &[f, s] : mp) {
    if (s.size() >= k) {
      sort(s.begin(), s.end());
      ans = min(ans, accumulate(s.begin(), s.begin() + k, 0));
    }
  }
  cout << ans << '\n';
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/