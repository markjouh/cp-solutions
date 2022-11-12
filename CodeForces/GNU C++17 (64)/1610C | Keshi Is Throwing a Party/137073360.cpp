#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<pair<int, int>> friends(n);
  for (auto& [f, s] : friends) {
   cin >> f >> s;
  }
  int l = 0, r = n + 1;
  while (l + 1 < r) {
   int mid = l + (r - l) / 2;
   int ct = 0;
   for (auto [f, s] : friends) {
    if (f >= mid - ct - 1 && s >= ct) {
     ++ct;
    }
   }
   if (ct >= mid) {
    l = mid;
   } else {
    r = mid;
   }
  }
  cout << l << '\n';
 }
}