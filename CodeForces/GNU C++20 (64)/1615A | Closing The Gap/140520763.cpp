#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully!
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   sum += x;
  }
  cout << (sum % n == 0 ? 0 : 1) << '\n';
 }
}