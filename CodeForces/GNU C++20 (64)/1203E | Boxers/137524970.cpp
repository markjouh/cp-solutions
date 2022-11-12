#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &x : v) {
    cin >> x;
  }
  sort(v.begin(), v.end());
  set<int> res;
  for (int i = 0; i < n; ++i) {
    for (int j = -1; j <= 1; ++j) {
      int c = v[i] + j;
      if (c && !res.count(c)) {
        res.insert(c);
        break;
      }
    }
  }
  cout << res.size() << '\n';
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/