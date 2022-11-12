#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int a, b, c;
  cin >> a >> b >> c;
  string res;
  if (a > 0) {
   res += string(a + 1, '0');
  }
  if (c > 0) {
   res += string(c + 1, '1');
  }
  int cur = 0;
  if (res.size() == 0) {
   b++;
  } else {
   if (a && c) {
    b--;
   }
   cur = res.back() == '0';
  }
  for (int i = 0; i < b; i++) {
   res += cur + '0';
   cur ^= 1;
  }
  cout << res << '\n';
 }
}