#include <bits/stdc++.h>
using namespace std;
 
set<int> sq;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 for (int i = 1; i * i <= 1e9; i++) {
  sq.insert(i * i);
 }
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  cout << ((n % 2 == 0 && sq.count(n / 2)) || (n % 4 == 0 && sq.count(n / 4)) ? "YES" : "NO") << '\n';
 }
}