#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   sum += a;
  }
  long long num = sum % n, diff = sum % n > 0;
  cout << num * (n - num) * diff << '\n';
 }
}