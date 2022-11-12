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
  map<int, int> m;
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   m[a]++;
  }
  priority_queue<int> p;
  for (auto x : m) {
   p.push(x.second);
  }
  int ans = n;
  while (p.size() >= 2) {
   int fst = p.top() - 1;
   p.pop();
   int sec = p.top() - 1;
   p.pop();
   ans -= 2;
   if (fst > 0) {
    p.push(fst);
   }
   if (sec > 0) {
    p.push(sec);
   }
  }
  cout << ans << '\n';
 }
}