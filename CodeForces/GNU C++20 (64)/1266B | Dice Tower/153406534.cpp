#include <bits/stdc++.h>
using namespace std;
 
const int mxn = 500;
int a[mxn][mxn];
 
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n * m == 1) {
    printf("0\n");
    return 0;
  }
  if (n == 1) {
    for (int i = 0; i < m; i++) {
      printf("%d ", i + 2);
    }
    return 0;
  }
  if (m == 1) {
    for (int i = 0; i < n; i++) {
      printf("%d\n", i + 2);
    }
    return 0;
  }
  int even = 0, odd = 1;
  if (m < n) {
      for (int i = 0; i < m; i++) {
      a[0][i] = even += 2;
    }
    for (int i = 1; i < n; i++) {
      a[i][0] = (even < odd ? even : odd) += 2;
    }
  } else {
    for (int i = 0; i < n; i++) {
      a[i][0] = even += 2;
    }
    for (int i = 1; i < m; i++) {
      a[0][i] = (even < odd ? even : odd) += 2;
    }
  }
  
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      a[i][j] = a[i][0] * a[0][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}