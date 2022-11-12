#include <bits/stdc++.h>
using namespace std;
 
int mxval(map<int, int, greater<int>> boxes, int mx) {
 for (auto x : boxes) {
  if (x.first <= mx && x.second > 0) {
   return x.first;
  }
 }
 return -1;
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n, w, x;
  cin >> n >> w;
  map<int, int, greater<int>> boxes;
  for (int i = 0; i < n; i++) {
   cin >> x;
   boxes[x]++;
  }
  int items = n, space = w, layers = 1;
  while (items > 0) {
   int val = mxval(boxes, space);
   if (val != -1) {
    space -= val;
    boxes[val]--;
    items--;
   } else {
    space = w;
    layers++;
   }
  }
  cout << layers << '\n';
 }
}