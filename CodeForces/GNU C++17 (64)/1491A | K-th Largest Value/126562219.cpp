#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, q;
 cin >> n >> q;
 set<int> ones;
 for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
  if (x) {
   ones.insert(i + 1);
  }
 }
 while (q--) {
  int t, k;
  cin >> t >> k;
  if (t == 1) {
   if (ones.count(k)) {
    ones.erase(k);
   } else {
    ones.insert(k);
   }
  } else {
   cout << (ones.size() >= k) << '\n';
  }
 }
}