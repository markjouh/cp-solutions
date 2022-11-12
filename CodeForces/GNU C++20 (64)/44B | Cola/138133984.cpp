#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, a, b, c;
 cin >> n >> a >> b >> c;
 int ans = 0;
 for (int i = 0; i <= b && i <= n; ++i) {
  for (int j = 0; j <= c && i + j * 2 <= n; ++j) {
   if (a / 2 >= n - i - j * 2) {
    ++ans;
   }
  }
 }
 cout << ans << '\n';
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 