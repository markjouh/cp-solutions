#include <bits/stdc++.h>
using namespace std;
 
int H, M, h, m;
 
bool check() {
 int arr[4] = {h % 10, h / 10, m % 10, m / 10};
 for (int &x : arr) {
  if (x == 2) {
   x = 5;
  } else if (x == 5) {
   x = 2;
  }
 }
 if (arr[0] * 10 + arr[1] >= M || arr[2] * 10 + arr[3] >= H) {
  return false;
 }
 int val = h * 100 + m;
 while (val > 0) {
  int x = val % 10;
  if (x == 3 || x == 4 || x == 6 || x == 7 || x == 9) {
   return false;
  }
  val /= 10;
 }
 return true;
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  scanf("%d%d%d:%d", &H, &M, &h, &m);
  while (!check()) {
   if (h == H - 1 && m == M - 1) {
    h = 0;
    m = 0;
   } else if (m == M - 1) {
    h++;
    m = 0;
   } else {
    m++;
   }
  }
  printf("%0*d:%0*d\n", 2, h, 2, m);
 }
}