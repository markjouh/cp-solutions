#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> cats(n);
  iota(cats.begin(), cats.end(), 1);
  for (int i = 0; i < n - n % 2; i += 2) {
   swap(cats[i], cats[i + 1]);
  }
  if (n % 2) swap(cats[n - 2], cats[n - 1]);
  for (int x : cats) cout << x << ' ';
  cout << '\n';
 }
}