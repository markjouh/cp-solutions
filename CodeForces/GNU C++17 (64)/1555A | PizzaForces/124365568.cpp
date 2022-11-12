#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  ll n;
  cin >> n;
  n = (n + 1) / 2;
  n = max(n, 3ll);
  cout << n * 5 << '\n';
 }
}