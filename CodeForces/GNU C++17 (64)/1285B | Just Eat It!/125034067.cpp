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
  vector<ll> pre(n + 1);
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
   int x;
   cin >> x;
   pre[i] = pre[i - 1] + x;
   sum += x;
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
   if (max(pre[n] - pre[i], pre[i - 1]) >= sum) {
    ok = false;
    break;
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}