#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int a, b;
  string s;
  cin >> a >> b >> s;
  s += ' ';
  int mines = 0;
  int last = s[0], cnt = 1;
  bool flag = false;
  vector<int> gaps;
  for (int i = 1; i < s.size(); i++) {
   if (s[i] != last) {
    if (last == '0' && flag) {
     gaps.push_back(cnt);
    }
    if (last == '1') {
     mines++;
     flag = true;
    }
    cnt = 0;
   }
   last = s[i];
   cnt++;
  }
  if (mines && gaps.size() == mines) {
   gaps.pop_back();
  }
  sort(gaps.begin(), gaps.end(), greater<int>());
  int ans = 0;
  while (gaps.size() && gaps.back() * b < a) {
   ans += gaps.back() * b;
   mines--;
   gaps.pop_back();
  }
  ans += mines * a;
  cout << ans << '\n';
 }
}