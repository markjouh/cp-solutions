#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
   string s;
   for (int k = 0; k < i; ++k) {
    s += '(';
   }
   for (int k = 0; k < i; ++k) {
    s += ')';
   }
   for (int k = 0; k < 2 * n - 2 * i; k += 2) {
    s += "()";
   }
   cout << s << '\n';
  }
 }
}