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
  vector<int> odd, even;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   (x % 2 ? odd : even).push_back(x);
  }
  for (int x : odd) {
   cout << x << ' ';
  }
  for (int x : even) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}