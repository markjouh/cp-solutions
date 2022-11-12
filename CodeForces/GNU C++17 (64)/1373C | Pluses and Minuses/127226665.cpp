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
  int sum = 0, mn = 0;
  ll ans = s.size();
  for (int i = 0; i < s.size(); i++) {
   sum += (s[i] == '-' ? -1 : 1);
   if (sum < mn) {
    mn = sum;
    ans += i + 1;
   }
  }
  cout << ans << '\n';
 }
}