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
  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++) {
   cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
   cin >> b[i];
  }
  int sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
   c[i] = b[i] - a[i];
   sum += c[i];
   cnt += abs(c[i]);
  }
  if (sum != 0) {
   cout << -1 << '\n';
   continue;
  }
  cout << cnt / 2 << '\n';
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    if (c[i] < 0 && c[j] > 0) {
     while (c[i] != 0 && c[j] != 0) {
      cout << i + 1 << ' ' << j + 1 << '\n';
      c[i]++;
      c[j]--;
     }
    }
   }
  }
 }
}