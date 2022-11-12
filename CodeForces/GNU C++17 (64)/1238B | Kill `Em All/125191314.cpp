#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, r;
  cin >> n >> r;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  sort(a.begin(), a.end(), greater<int>());
  int cnt = 0;
  for (int i = 0; i < n; i++) {
   if (i > 0 && a[i] == a[i - 1]) {
    continue;
   }
   if (a[i] <= cnt * r) {
    break;
   }
   cnt++;
  }
  cout << cnt << '\n';
 }
}