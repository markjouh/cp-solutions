#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int mxn = 15e4;
 
int n;
int a[mxn][2];
 
vector<int> pfact(int x) {
  vector<int> r;
  for (int i = 2; i*i <= x; i++) {
    if (x % i == 0) {
      r.push_back(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    r.push_back(x);
  }
  return r;
}
 
bool check(int x) {
  for (int i = 0; i < n; i++) {
    if (a[i][0] % x && a[i][1] % x) {
      return false;
    }
  }
  return true;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int x : pfact(a[0][i])) {
      if (check(x)) {
        cout << x << '\n';
        return 0;
      }
    }
  }
  cout << -1 << '\n';
}