#include <bits/stdc++.h>
using namespace std;
 
int arr[200000], res[200000];
 
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
  int mn = 2e9;
  for (int i = n - 1; i >= 0; i--) {
   mn = min(mn, i - arr[i]);
   arr[i] = mn < i;
  }
  for (int i = 0; i < n; i++) {
   cout << arr[i] << ' ';
  }
  cout << '\n';
 }
}