#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int A, B, C;
 cin >> A >> B >> C;
 int ans = 0;
 for (int i = 0; i < 7; i++) {
  int f_a = 0, f_b = 0, f_c = 0;
  for (int j = 0; j < 7; j++) {
   int id = (i + j) % 7;
   (id == 0 || id == 3 || id == 6 ? f_a : (id == 1 || id == 5 ? f_b : f_c))++;
  }
  int a = A, b = B, c = C, full = min({a / f_a, b / f_b, c / f_c}), cur = full * 7;
  a -= full * f_a;
  b -= full * f_b;
  c -= full * f_c;
  for (int j = 0; j < 7; j++) {
   int id = (i + j) % 7;
   if ((id == 0 || id == 3 || id == 6 ? a : (id == 1 || id == 5 ? b : c))-- > 0) {
    cur++;
   } else {
    break;
   }
  }
  ans = max(ans, cur);
 }
 cout << ans << '\n';
}