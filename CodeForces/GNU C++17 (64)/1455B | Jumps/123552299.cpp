#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int x;
  cin >> x;
  int pos = 0, cnt = 1;
  while (pos < x) {
   pos += cnt;
   cnt++;
  }
  cout << cnt - 1 + (pos - x == 1) << '\n';
 }
}