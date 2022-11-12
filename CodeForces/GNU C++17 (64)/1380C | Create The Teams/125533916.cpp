#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, t;
  cin >> n >> t;
  deque<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  sort(a.begin(), a.end(), greater<int>());
  int sub = 0, ans = 0;
  for (int i = 0; i < n; i++) {
   if (a[i] * (i + 1 - sub) >= t) {
    ans++;
    sub = i + 1;
   }
  }
  cout << ans << '\n';
 }
}