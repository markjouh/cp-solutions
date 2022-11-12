#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// cloudcloud
 
int M = 998244353;
 
int m_add(int a, int b) {
 a += b;
 while (a >= M) {
  a -= M;
 }
 while (a < 0) {
  a += M;
 }
 return a;
}
 
int m_mul(int a, int b) {
 return 1ll * a * b % M;
}
 
int m_exp(int a, int b) {
 int res = 1;
 while (b > 0) {
  if (b % 2) {
   res = m_mul(res, a);
  }
  a = m_mul(a, a);
  b /= 2;
 }
 return res;
}
 
int m_div(int a, int b) {
 return m_mul(a, m_exp(b, M - 2));
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> fib(max(3, n + 1));
 fib[0] = fib[1] = fib[2] = 1;
 for (int i = 3; i <= n; ++i) {
  fib[i] = m_add(fib[i - 1], fib[i - 2]);
 } 
 cout << m_div(fib[n], m_exp(2, n)) << '\n';
}