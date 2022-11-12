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
  vector<int> v(n);
  long long avg = 0;
  for (int &x : v) {
   cin >> x;
   avg += x;
  }
  if (avg % n) {
   cout << -1 << '\n';
   continue;
  }
  avg /= n;
  int ans = 0;
  for (int x : v) {
   if (x > avg) {
    ans++;
   }
  }
  cout << ans << '\n';
 }
}