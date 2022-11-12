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
  vector<int> v(1);
  for (int i = 0; i < n; i++) {
   int a;
   cin >> a;
   if (a <= v[0]) {
    v.push_back(a);
   } else {
    v[0] = a;
   }
   sort(v.begin(), v.end());
  }
  cout << v.size() << '\n';
 }
}