#include <bits/stdc++.h>
using namespace std;
 
deque<int> res;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  if (n < 4) {
   cout << -1 << '\n';
   continue;
  }
  for (int i = 1; i <= n; i++) {
   if (i % 2) {
    res.push_front(i);
   } else {
    if (i == 2) {
     res.push_back(4);
    } else if (i == 4) {
     res.push_back(2);
    } else {
     res.push_back(i);
    }
   }
  }
  for (auto x : res) {
   cout << x << ' ';
  }
  cout << '\n';
  res.clear();
 }
}