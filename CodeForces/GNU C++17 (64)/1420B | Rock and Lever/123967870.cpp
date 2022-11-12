#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  long long ans = 0;
  for (int i = 0; i <= 29; i++) {
   long long cnt = 0;
   for (int x : a) {
    if (x >= (1 << i) && x < (1 << (i + 1))) {
     cnt++;
    }
   }
   ans += cnt * (cnt - 1) / 2;
  }
  cout << ans << '\n';
 }
}