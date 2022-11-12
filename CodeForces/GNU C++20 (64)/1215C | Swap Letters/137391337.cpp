#include <bits/stdc++.h>
using namespace std;
 
int cnt(string s, char c) {
  return count(s.begin(), s.end(), c);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s, t;
  cin >> n >> s >> t;
  if (s == t) {
    cout << 0 << '\n';
    return 0;
  }
  if (cnt(s + t, 'a') % 2 || cnt(s + t, 'b') % 2) {
    cout << -1 << '\n';
    return 0;
  }
  map<pair<char, char>, vector<int>> mp;
  vector<pair<int, int>> res;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      pair<int, int> p = {s[i], t[i]};
      if (mp[p].size()) {
        res.push_back({mp[p].back(), i});
        mp[p].pop_back();
      } else {
        mp[p].push_back(i);
      }
    }
  }
  if (mp[{'a', 'b'}].size()) {
    res.push_back({mp[{'a', 'b'}].back(), mp[{'a', 'b'}].back()});
    res.push_back({mp[{'a', 'b'}].back(), mp[{'b', 'a'}].back()});
  }
  cout << res.size() << '\n';
  for (auto [f, s] : res) {
    cout << f + 1 << ' ' << s + 1 << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/