#include <bits/stdc++.h>
using namespace std;
 
int arr[100000];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  int mex = 0, max = 0;
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
   if (arr[i] == mex) mex++;
   if (arr[i] > max) max = arr[i];
  }
  if (k == 0) {
   cout << n << '\n';
  } else if (mex > max) {
   cout << n + k << '\n';
  } else {
   cout << (count(arr, arr + n, (mex + max + 1) / 2) ? n : n + 1) << '\n';
  }
 }
}