#include <bits/stdc++.h>
using namespace std;
 
int arr[100], res[100];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  for (int i = 0; i < n; i += 2) {
   int a = arr[i], b = -arr[i + 1];
   res[i] = b;
   res[i + 1] = a;
  }
  for (int i = 0; i < n; i++) {
   cout << res[i] << ' ';
  }
  cout << '\n';
 }
}