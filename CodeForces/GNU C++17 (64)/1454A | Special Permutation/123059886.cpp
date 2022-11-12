#include <bits/stdc++.h>
using namespace std;
 
deque<int> res;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  int a[n];
  iota(a, a + n, 1);
  reverse(a, a + n);
  if (n % 2) {
   swap(a[0], a[n / 2]);
  }
  for (int x : a) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}