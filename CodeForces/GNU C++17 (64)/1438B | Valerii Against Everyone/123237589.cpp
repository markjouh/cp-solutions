#include <bits/stdc++.h>
using namespace std;
 
void run_case() {
 int n;
 cin >> n;
 set<int> s;
 bool ok = false;
 for (int i = 0; i < n; i++) {
  int a;
  cin >> a;
  if (s.count(a)) {
   ok = true;
  }
  s.insert(a);
 }
 cout << (ok ? "YES" : "NO") << '\n';
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  run_case();
 }
}