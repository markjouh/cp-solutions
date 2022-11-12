#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  int ans = 0;
  while (n % 6 == 0) {
   n /= 6;
   ++ans;
  }
  while (n % 3 == 0) {
   n /= 3;
   ans += 2;
  }
  cout << (n == 1 ? ans : -1) << '\n';
 }
}