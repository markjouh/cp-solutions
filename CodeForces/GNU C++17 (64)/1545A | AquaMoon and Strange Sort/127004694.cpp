#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> even, odd;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   (i % 2 == 0 ? even : odd).push_back(x);
  }
  sort(even.begin(), even.end(), greater<int>());
  sort(odd.begin(), odd.end(), greater<int>());
  vector<int> res;
  for (int i = 0; i < n; i++) {
   if (i % 2 == 0) {
    res.push_back(even.back());
    even.pop_back();
   } else {
    res.push_back(odd.back());
    odd.pop_back();
   }
  }
  auto sorted = [&](vector<int> v) {
   for (int i = 1; i < v.size(); i++) {
    if (v[i] < v[i - 1]) {
     return false;
    }
   }
   return true;
  };
  cout << (sorted(res) ? "YES" : "NO") << '\n';
 }
}