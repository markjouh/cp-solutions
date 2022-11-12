#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  auto solve = [&](char a, char b) {
   int res = 0;
   for (char c : s) {
    if (c == a) {
     res++;
     swap(a, b);
    }
   }
   if (a != b && res % 2) {
    res--;
   }
   return res;
  };
  int best = INT_MIN;
  for (char x = '0'; x <= '9'; x++) {
   for (char y = '0'; y <= '9'; y++) {
    best = max(best, solve(x, y));
   }
  }
  cout << s.size() - best << '\n';
 }
}