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
  reverse(s.begin(), s.end());
  int ans = 1e9;
  vector<pair<char, char>> endings{{'0', '0'}, {'2', '5'}, {'5', '0'}, {'7', '5'}};
  for (auto [a, b] : endings) {
   int cnt = 0;
   for (int i = 0; i < s.size(); i++) {
    if (cnt == 0 && s[i] == b) {
     cnt = 1;
    } else if (cnt == 1 && s[i] == a) {
     cnt = 2;
    }
    if (cnt == 2) {
     ans = min(ans, i - 1);
     break;
    }
   }
  }
  cout << ans << '\n';
 }
}