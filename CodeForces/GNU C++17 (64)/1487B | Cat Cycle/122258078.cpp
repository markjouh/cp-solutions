#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  k--;
  int jumps = (n % 2) * (k / (n / 2));
  cout << (k + jumps) % n + 1 << '\n';
 }
}