#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int a, b;
  cin >> a >> b;
  cout << (abs(a - b) + 9) / 10 << '\n';
 }
}