#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 int arr[n];
 int sum = 0;
 for (int &x : arr) {
  cin >> x;
  if (x % 2 == 0) {
   x /= 2;
  } else if (x > 0) {
   if (sum < 0) {
    x = (x + 1) / 2;
    sum++;
   } else {
    x /= 2;
    sum--;
   }
  } else if (x < 0) {
   if (sum < 0) {
    x /= 2;
    sum++;
   } else {
    x = (x - 1) / 2;
    sum--;
   }
  }
 }
 for (int x : arr) {
  cout << x << '\n';
 }
}