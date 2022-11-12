#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int cost(string s, char c) {
 return s.size() - count(s.begin(), s.end(), c);
}
 
string half(string s, int side) {
 if (side == 0) {
  return s.substr(0, s.size() / 2);
 } else {
  return s.substr(s.size() / 2, s.size());
 }
}
 
int dfs(string s, int cur, int side, char c) {
 if (s.size() == 1) {
  return cur + (s[0] != c);
 }
 cur += cost(half(s, side), c);
 s = half(s, side ^ 1);
 c++;
 return min(dfs(s, cur, 0, c), dfs(s, cur, 1, c));
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string s;
  cin >> n >> s;
  if (n == 1) {
   cout << (s[0] != 'a') << '\n';
   continue;
  }
  cout << min({
   dfs(half(s, 0), cost(half(s, 1), 'a'), 0, 'b'),
   dfs(half(s, 0), cost(half(s, 1), 'a'), 1, 'b'),
   dfs(half(s, 1), cost(half(s, 0), 'a'), 0, 'b'),
   dfs(half(s, 1), cost(half(s, 0), 'a'), 1, 'b'),
  }) << '\n';
 }
}