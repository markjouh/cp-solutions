#include <bits/stdc++.h>
using namespace std;
 
int arr[200000];
pair<int, int> vals[5000005];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 for (int i = 0; i < n; i++) {
  cin >> arr[i];
 }
 for (int i = 0; i < n; i++) {
  for (int j = i + 1; j < n; j++) {
   auto x = vals[arr[i] + arr[j]];
   if (x.first != 0 || x.second != 0) {
    if (x.first != i && x.first != j && x.second != i && x.second != j) {
     cout << "YES" << '\n';
     cout << x.first + 1 << ' ' << x.second + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
     return 0;
    }
   }
   vals[arr[i] + arr[j]] = {i, j};
  }
 }
 cout << "NO" << '\n';
 }