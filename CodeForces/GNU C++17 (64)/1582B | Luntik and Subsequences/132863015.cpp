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
  ll sum = 0;
  int ones = 0, zeroes = 0;
  for (int i = 0; i < n; ++i) {
   int x;
   cin >> x;
   if (x == 0) {
    zeroes++;
   }
   if (x == 1) {
    ones++;
   }
   sum += x;
  }
  cout << ones * (ll)pow(2, zeroes) << '\n';
 }
}