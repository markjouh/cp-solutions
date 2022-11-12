#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, r;
  cin >> n >> r;
  int cnt = 0, sum = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   sum += x;
   cnt += (x == r);
  }
  if (cnt == n) {
   cout << 0 << '\n';
  } else if (sum == n * r || cnt) {
   cout << 1 << '\n';
  } else {
   cout << 2 << '\n';
  }
 }
}