#include <bits/stdc++.h>
using namespace std;
 
// Testing array speed (vectors, c-style, global, etc)
 
const int N = 2e5;
int a[N], resmn[N], resmx[N];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    // At each index, we set the new max if needed. Otherwise,
    // The min array gets the smallest possible untaken number
    // The max array gets the largest possible untaken number < cur max
    set<int> stmn, stmx;
    int cmx = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > cmx) {
        resmn[i] = a[i];
        resmx[i] = a[i];
        for (int j = a[i]-1; j > cmx; j--) {
          stmn.insert(j);
          stmx.insert(j);
        }
        cmx = a[i];
      } else {
        resmn[i] = *stmn.begin();
        stmn.erase(resmn[i]);
        resmx[i] = *--stmx.end();
        stmx.erase(resmx[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << resmn[i] << " \n"[i == n-1];
    }
    for (int i = 0; i < n; i++) {
      cout << resmx[i] << " \n"[i == n-1];
    }
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/