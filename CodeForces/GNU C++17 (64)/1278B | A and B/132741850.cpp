#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int tri(int x) {
 return x * (x + 1) / 2;
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  int diff = abs(a - b);
  while (tri(cnt) < diff || tri(cnt) % 2 != diff % 2) {
   cnt++;
  }
  cout << cnt << '\n';
 }
}