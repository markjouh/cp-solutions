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
  if (n == 2) {
   cout << -1 << '\n';
   continue;
  }
  int l = 1, r = (n * n + 1) / 2 + 1;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
    if ((j + i) % 2) {
     cout << r << ' ';
     r++;
    } else {
     cout << l << ' ';
     l++;
    }
   }
   cout << '\n';
  }
 }
}