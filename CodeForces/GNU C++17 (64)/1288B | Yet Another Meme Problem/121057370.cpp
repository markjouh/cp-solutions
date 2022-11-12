#include <bits/stdc++.h>
using namespace std;
 
int numlen(int x) {
 int res = 0;
 while (x > 0) {
  x /= 10;
  res++;
 }
 return res;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long a, b;
  cin >> a >> b;
  cout << a * (numlen(b + 1) - 1) << '\n';
 }
}