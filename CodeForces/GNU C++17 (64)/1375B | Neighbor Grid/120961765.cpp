#include <bits/stdc++.h>
using namespace std;
 
int arr[300][300];
 
inline int allneighbors(int i, int j, int n, int m) {
 int res = 0;
 if (i > 0) res++;
 if (i < n - 1) res++;
 if (j > 0) res++;
 if (j < m - 1) res++;
 return res;
}
 
void solve() {
 int n, m;
 cin >> n >> m;
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   cin >> arr[i][j];
  }
 }
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   int neighbors = allneighbors(i, j, n, m);
   if (arr[i][j] > neighbors) {
    cout << "NO" << '\n';
    return;
   }
   arr[i][j] = neighbors;
  }
 }
 cout << "YES" << '\n';
 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   cout << arr[i][j] << ' ';
  }
  cout << '\n';
 }
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  solve();
 }
}