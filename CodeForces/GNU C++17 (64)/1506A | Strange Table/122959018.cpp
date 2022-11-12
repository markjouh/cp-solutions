#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long n, m, x;
  cin >> n >> m >> x;
  cout << (x - 1) % n * m + (x + n - 1) / n << '\n';
 }
}