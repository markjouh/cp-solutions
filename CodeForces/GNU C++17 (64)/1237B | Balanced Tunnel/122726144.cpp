#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 int a[n], b[n], c[n], pos[n];
 for (auto &x : a) {
  cin >> x;
  x--;
 }
 for (auto &x : b) {
  cin >> x;
  x--;
 }
 for (int i = 0; i < n; i++) {
  pos[b[i]] = i;
 }
 for (int i = 0; i < n; i++) {
  c[i] = pos[a[i]];
 }
 int mx = -1, ans = 0;
 for (int x : c) {
  if (x > mx) {
   mx = x;
  } else {
   ans++;
  }
 }
 cout << ans << '\n';
}