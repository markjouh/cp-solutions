#include <bits/stdc++.h>
using namespace std;
 
int a[100], b[100];
 
void dfs(int l, int r, int d) {
 if (l >= r) {
  return;
 }
 int mx = 0, pos;
 for (int i = l; i < r; i++) {
  if (a[i] > mx) {
   mx = a[i];
   pos = i;
  }
 }
 b[pos] = d;
 d++;
 dfs(l, pos, d);
 dfs(pos + 1, r, d);
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
   scanf("%d", &a[i]);
  }
  fill(b, b + n, 0);
  dfs(0, n, 0);
  for (int i = 0; i < n; i++) {
   printf("%d ", b[i]);
  }
  printf("\n");
 }
}