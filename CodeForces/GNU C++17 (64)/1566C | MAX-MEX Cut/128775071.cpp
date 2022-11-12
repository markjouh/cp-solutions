#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  auto solve = [&](string s) {
   int res = count(s.begin(), s.end(), '0');
   bool a = false, b = false;
   for (char c : s) {
    if (c == '0') {
     a = true;
    } else {
     b = true;
    }
    if (a && b) {
     res++;
     a = b = false;
    }
   }
   return res;
  };
  int ans = 0;
  string s;
  for (int i = 0; i < n; i++) {
   if (s1[i] != s2[i]) {
    ans += 2 + solve(s);
    s.clear();
   } else {
    s += s1[i];
   }
  }
  cout << ans + solve(s) << '\n';
 }
}