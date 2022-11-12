#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n);
  ll sum = 0;
  for (int &x : a) {
   cin >> x;
   sum += x;
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
   if (sum % i == 0) {
    bool flag = true;
    ll req = sum / i, cur = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
     cur += a[j];
     cnt++;
     if (cur == req) {
      cur = 0;
      cnt--;
     }
     if (cur > req) {
      flag = false;
     }
    }
    if (flag) {
     ans = min(ans, cnt);
    }
   }
  }
  cout << ans << '\n';
 }
}