#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<char> a(n + 2), b(n + 2);
  for (int i = 1; i <= n; i++) {
   cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
   cin >> b[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
   if (b[i] != '1') {
    continue;
   }
   if (a[i] == '0') {
    ans++;
   } else if (a[i - 1] == '1') {
    a[i - 1] = 'x';
    ans++;
   } else if (a[i + 1] == '1') {
    a[i + 1] = 'x';
    ans++;
   }
  }
  cout << ans << '\n';
 }
}