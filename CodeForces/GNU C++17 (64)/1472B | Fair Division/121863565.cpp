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
  int ones = 0, twos = 0;
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   (a == 1 ? ones : twos)++;
  }
  bool ans = ones % 2 == 0;
  if (twos % 2 && ones < 2) {
   ans = false;
  }
  cout << (ans ? "YES" : "NO") << '\n';
 }
}