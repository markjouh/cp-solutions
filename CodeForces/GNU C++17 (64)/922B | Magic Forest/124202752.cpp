#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 int ans = 0;
 for (int i = 1; i <= n; i++) {
  for (int j = i; j <= n; j++) {
   int k = i ^ j;
   if (k >= j && k < i + j && k <= n) {
    ans++;
   }
  }
 }
 cout << ans << '\n';
}