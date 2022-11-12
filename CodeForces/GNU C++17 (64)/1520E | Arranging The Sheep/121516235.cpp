#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  string s;
  cin >> n >> s;
  vector<int> v;
  int dist = 0;
  for (char c : s) {
   if (c == '.') {
    dist++;
   } else {
    v.emplace_back(dist);
   }
  }
  if (v.empty()) {
   cout << 0 << '\n';
   continue;
  }
  int mid = v[v.size() / 2];
  long long ans = 0;
  for (int x : v) {
   ans += abs(mid - x);
  }
  cout << ans << '\n';
 }
}