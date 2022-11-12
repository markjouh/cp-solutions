#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  auto solve = [&]() {
   vector<int> res(3);
   for (int i = 2; i * i <= n; i++) for (int j = i + 1; j * j <= n / i; j++) {
    int k = n / i / j;
    if (n % i == 0 && n / i % j == 0 && k != i && k != j) {
     res = {i, j, n / i / j};
     return res;
    }
   }
   return res;
  };
  vector<int> res = solve();
  if (res[0]) {
   cout << "YES" << '\n';
   for (int x : res) {
    cout << x << ' ';
   }
   cout << '\n';
  } else {
   cout << "NO" << '\n';
  }
 }
}