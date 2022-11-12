#include <bits/stdc++.h>
using namespace std;
 
pair<int, int> getratio(int x, int y) {
 int g = gcd(x, y);
 return {x / g, y / g};
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  string s;
  cin >> n >> s;
  int d = 0, k = 0;
  map<pair<int, int>, int> m;
  for (int i = 0; i < n; i++) {
   (s[i] == 'D' ? d : k)++;
   cout << ++m[getratio(d, k)] << ' ';
  }
  cout << '\n';
 }
}