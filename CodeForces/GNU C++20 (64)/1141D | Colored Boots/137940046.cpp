#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 string a, b;
 cin >> n >> a >> b;
 vector<vector<int>> l(27), r(27);
 for (int i = 0; i < n; ++i) { 
  (a[i] == '?' ? l[26] : l[a[i] - 'a']).push_back(i + 1);
  (b[i] == '?' ? r[26] : r[b[i] - 'a']).push_back(i + 1);
 }
 vector<pair<int, int>> res;
 for (int i = 0; i < 26; ++i) {
  while (!l[i].empty() && !r[i].empty()) {
   res.push_back({l[i].back(), r[i].back()});
   l[i].pop_back();
   r[i].pop_back();
  }
 }
 for (int i = 0; i < 26; ++i) {
  while (!l[26].empty() && !r[i].empty()) {
   res.push_back({l[26].back(), r[i].back()});
   l[26].pop_back();
   r[i].pop_back();
  }
  while (!l[i].empty() && !r[26].empty()) {
   res.push_back({l[i].back(), r[26].back()});
   l[i].pop_back();
   r[26].pop_back();
  }
 }
 while (!l[26].empty() && !r[26].empty()) {
  res.push_back({l[26].back(), r[26].back()});
  l[26].pop_back();
  r[26].pop_back();
 }
 cout << res.size() << '\n';
 for (auto [f, s] : res) {
  cout << f << ' '  << s << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 