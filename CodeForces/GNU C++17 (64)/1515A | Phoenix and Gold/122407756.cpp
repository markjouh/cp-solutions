#include <bits/stdc++.h>
using namespace std;
 
void run_case() {
 int n, illegal;
 cin >> n >> illegal;
 int arr[n];
 for (int &x : arr) {
  cin >> x;
 }
 for (int i = 0; i < n; i++) {
  int sum = 0;
  bool flag = true;
  for (int x : arr) {
   sum += x;
   if (sum == illegal) {
    flag = false;
    break;
   }
  }
  if (flag) {
   cout << "YES" << '\n';
   for (int x : arr) {
    cout << x << ' ';
   }
   cout << '\n';
   return;
  }
  swap(arr[i], arr[i + 1]);
 }
 cout << "NO" << '\n';
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  run_case();
 }
}