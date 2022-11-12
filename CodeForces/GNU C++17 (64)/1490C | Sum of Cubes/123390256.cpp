#include <bits/stdc++.h>
using namespace std;
 
unordered_set<long long> cubes;
 
int main() {
 for (long long i = 1; i <= 10000; i++) {
  cubes.insert(i * i * i);
 }
 int t;
 cin >> t;
 while (t--) {
  long long x;
  scanf("%lld", &x);
  bool ok = false;
  for (long long y : cubes) {
   if (cubes.count(x - y)) {
    ok = true;
    break;
   }
  }
  printf("%s", ok ? "YES\n" : "NO\n");
 }
}