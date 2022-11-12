#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  bool flag = false;
  int mx = 0;
  for (int &x : a) {
   cin >> x;
   if (x == t) {
    flag = true;
   }
   mx = max(mx, x);
  }
  if (flag) {
   cout << 1 << '\n';
  } else {
   cout << max(2, (t + mx - 1) / mx) << '\n';
  }
 }
}