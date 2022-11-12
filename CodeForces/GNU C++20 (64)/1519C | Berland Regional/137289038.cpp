#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> school(n), skill(n);
    for (int &x : school) {
      cin >> x;
      --x;
    }
    for (int &x : skill) {
      cin >> x;
    }
    vector<vector<long long>> pre(n);
    for (int i = 0; i < n; ++i) {
      pre[school[i]].push_back(skill[i]);
    }
    for (int i = 0; i < n; ++i) {
      sort(pre[i].begin(), pre[i].end(), greater<int>());
      for (int j = 1; j < pre[i].size(); ++j) {
        pre[i][j] += pre[i][j - 1];
      }
    }
    vector<long long> res(n);
    for (int i = 0; i < n; ++i) {
      int m = pre[i].size();
      for (int j = 1; j <= m; ++j) {
        res[j - 1] += pre[i][m - m % j - 1];
      }
    }
    for (long long x : res) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/