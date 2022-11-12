#include <bits/stdc++.h>
using namespace std;
 
int c[100000], a[100000], b[100000];
 
inline long long convert(int x, int y) {
 return (long long)(x * 1e5) + y;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  map<int, set<int>> m;
  for (int i = 0; i < n; i++) {
   cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
   cin >> b[i];
  }
  long long last = 0, ans = 0;
  for (int i = 1; i < n; i++) {
   long long cur = c[i] + 1ll + abs(a[i] - b[i]);
   if (a[i] != b[i]) {
    cur = max(cur, c[i] + 1ll - abs(a[i] - b[i]) + last);
   }
   ans = max(ans, cur);
   last = cur;
  }
  cout << ans << '\n';
 }
}