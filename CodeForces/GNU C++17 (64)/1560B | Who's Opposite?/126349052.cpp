#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int a, b, c;
  cin >> a >> b >> c;
  int diff = abs(a - b), sz = diff * 2;
  if (a > sz || b > sz || c > sz) {
   cout << -1 << '\n';
   continue;
  }
  if (c + diff <= sz && c + diff != a && c + diff != b) {
   cout << c + diff << '\n';
  } else if (c - diff <= sz && c - diff >= 1 && c - diff != a && c - diff != b) {
   cout << c - diff << '\n';
  } else {
   cout << -1 << '\n';
  }
 }
}