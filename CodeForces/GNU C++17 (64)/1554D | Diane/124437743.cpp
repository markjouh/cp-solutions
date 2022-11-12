#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  if (n <= 26) {
   for (char c = 'a'; c <= n - 1 + 'a'; c++) {
    cout << c;
   }
   cout << '\n';
   continue;
  }
  string s = string(n, 'a');
  s[n / 2] = 'b';
  if (n % 2) {
   s[n / 2 + 1] = 'c';
  }
  cout << s << '\n';
 }
}