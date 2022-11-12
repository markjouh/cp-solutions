#include <bits/stdc++.h>
using namespace std;
 
const string start = "989";
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  cout << start.substr(0, n);
  for (int i = 0; i < max(0, n - 3); i++) {
   cout << i % 10;
  }
  cout << '\n';
 }
}