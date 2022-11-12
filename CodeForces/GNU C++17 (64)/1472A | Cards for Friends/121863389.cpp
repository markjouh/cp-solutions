#include <bits/stdc++.h>
using namespace std;
 
void run_case() {
 int w, h, n;
 cin >> w >> h >> n;
 long long cur = 1;
 while (cur < n) {
  if (w % 2 == 0) {
   w /= 2;
   cur *= 2;
  } else if (h % 2 == 0) {
   h /= 2;
   cur *= 2;
  } else {
   cout << "NO" << '\n';
   return;
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
  run_case();
 }
}