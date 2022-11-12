#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  map<char, int> mp;
  for (char c : s) {
   mp[c]++;
  }
  char c;
  int hi = 0;
  for (auto [x, y] : mp) {
   if (y > hi) {
    c = x;
    hi = y;
   }
  }
  map<char, char> conv = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
  c = conv[c];
  cout << string(s.size(), c) << '\n';
 }
}