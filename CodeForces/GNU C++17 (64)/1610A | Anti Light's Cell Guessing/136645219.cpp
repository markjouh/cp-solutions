#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
   cout << 0 << '\n';
   continue;
  }
  cout << min(2, min(n, m)) << '\n';
 }
}