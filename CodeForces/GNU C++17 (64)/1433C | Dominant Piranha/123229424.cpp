#include <bits/stdc++.h>
using namespace std;
 
void run_case() {
 int n;
 cin >> n;
 int a[n];
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 int mx = *max_element(a, a + n);
 for (int i = 0; i < n; i++) {
  if (a[i] != mx) {
   continue;
  }
  int l = i - 1, r = i + 1, cur = a[i];
  while (l > -1 || r < n) {
   if (l >= 0 && cur > a[l]) {
    l--;
   } else if (r <= n - 1 && cur > a[r]) {
    r++;
   } else break;
   cur++;
  }
  if (l < 0 && r > n - 1) {
   cout << i + 1 << '\n';
   return;
  }
 }
 cout << -1 << '\n';
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  run_case();
 }
}