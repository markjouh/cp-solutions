#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  vector<int> can(3);
  for (int& x : can) {
   cin >> x;
  }
  cout << max(0, max(can[1], can[2]) + 1 - can[0]) << ' '
  << max(0, max(can[0], can[2]) + 1 - can[1]) << ' '
  << max(0, max(can[0], can[1]) + 1 - can[2]) << '\n';
 }
}