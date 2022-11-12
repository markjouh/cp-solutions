#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> v(n), pos(n);
  for (int i = 0; i < n; i++) {
   cin >> v[i];
   pos[v[i] - 1] = i;
  }
  int r = n;
  for (int i = n - 1; i >= 0; i--) {
   if (pos[i] > r) continue;
   for (int j = pos[i]; j < r; j++) {
    cout << v[j] << ' ';
   }
   r = pos[i];
  }
  cout << '\n';
 }
}