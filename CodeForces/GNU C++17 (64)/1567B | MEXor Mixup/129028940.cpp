#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 vector<int> prexor(300001);
 for (int i = 1; i <= 300000; i++) {
  prexor[i] = prexor[i - 1] ^ i;
 }
 while (tc--) {
  int a, b;
  cin >> a >> b;
  int x = prexor[a - 1];
  if (x == b) {
   cout << a << '\n';
  } else if ((x ^ b) != a) {
   cout << a + 1 << '\n';
  } else {
   cout << a + 2 << '\n';
  }
 }
}