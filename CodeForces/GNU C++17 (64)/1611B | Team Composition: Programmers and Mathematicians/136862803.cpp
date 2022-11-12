#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int a, b;
  cin >> a >> b;
  cout << min({a, b, (a + b) / 4}) << '\n';
 }
}