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
 
int create(int len) {
 int res = 0;
 while (len > 0) {
  res *= 10;
  res++;
  len--;
 }
 return res;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  int len = numlen(n);
  int ans = max(0, len - 1) * 9;
  ans += n / create(len);
  cout << ans << '\n';
 }
}