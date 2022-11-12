#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, m;
  cin >> n >> m;
  int state = 0;
  for (int i = 0; i < n; i++) {
   for (int j = 0; j < m; j++) {
    int a;
    cin >> a;
    cout << a + (a % 2 != state ? 1 : 0) << ' ';
    state ^= 1;
   }
   if (m % 2 == 0) {
    state ^= 1;
   }
   cout << '\n';
  }
 }
}