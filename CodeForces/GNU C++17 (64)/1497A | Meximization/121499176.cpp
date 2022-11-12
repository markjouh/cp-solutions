#include <bits/stdc++.h>
using namespace std;
 
int arr[100];
 
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
  vector<int> a, b;
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
   if (!i || a.back() != arr[i]) {
    a.push_back(arr[i]);
   } else {
    b.push_back(arr[i]);
   }
  }
  for (int x : a) {
   cout << x << ' ';
  }
  for (int x : b) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}