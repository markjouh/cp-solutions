#include <bits/stdc++.h>
using namespace std;
 
int arr[5000];
 
bool uniform(int n) {
 for (int i = 1; i < n; i++) {
  if (arr[i] != arr[0]) return false;
 }
 return true;
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  int idx = -1;
  for (int i = 0; i < n; i++) {
   if (arr[i] != arr[0]) {
    idx = i;
    break;
   }
  }
  if (idx == -1) {
   cout << "NO" << '\n';
   continue;
  }
  cout << "YES" << '\n';
  cout << 1 << ' ' << idx + 1 << '\n';
  for (int i = 1; i < n; i++) {
   if (i == idx) continue;
   cout << i + 1 << ' ' << (arr[i] != arr[0] ? 1 : idx + 1) << '\n';
  }
 }
}