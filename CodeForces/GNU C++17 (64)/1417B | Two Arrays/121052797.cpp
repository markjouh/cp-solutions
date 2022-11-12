#include <bits/stdc++.h>
using namespace std;
 
int arr[100000];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, u;
  cin >> n >> u;
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  int val = 0;
  for (int i = 0; i < n; i++) {
   if (arr[i] * 2 == u) {
    cout << val << ' ';
    val ^= 1;
   } else {
    cout << (2 * arr[i] < u ? 0 : 1) << ' ';
   }
  }
  cout << '\n';
 }
}