#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int k;
  cin >> k;
  int ans = 0;
  for (int i = 0; i < k; i++) {
   ans++;
   while (ans % 3 == 0 || ans % 10 == 3) {
    ans++;
   }
  }
  cout << ans << '\n';
 }
}