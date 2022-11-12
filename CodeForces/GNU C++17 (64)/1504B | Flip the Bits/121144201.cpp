#include <bits/stdc++.h>
using namespace std;
 
int legal[300000];
 
void solve() {
 int n;
 string a, b;
 cin >> n >> a >> b;
 int cnt0 = 0, cnt1 = 0;
 for (int i = 0; i < n; i++) {
  (a[i] == '0' ? cnt0 : cnt1)++;
  legal[i] = (cnt0 == cnt1);
 }
 int flipped = 0;
 for (int i = n - 1; i >= 0; i--) {
  if ((a[i] == b[i]) == flipped) {
   if (legal[i]) {
    flipped ^= 1;
   } else {
    cout << "NO" << '\n';
    return;
   }
  }
 }
 cout << "YES" << '\n';
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  solve();
 }
}