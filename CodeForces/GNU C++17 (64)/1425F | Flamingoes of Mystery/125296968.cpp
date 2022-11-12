#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 auto query = [&](int a, int b) {
  cout << '?' << ' ' << a << ' ' << b << endl;
  int x;
  cin >> x;
  return x;
 };
 int n;
 cin >> n;
 vector<int> pre(n + 1);
 for (int i = 2; i <= n; i++) {
  pre[i] = query(1, i);
 }
 pre[1] = pre[n] - query(2, n);
 cout << '!' << ' ';
 for (int i = 1; i <= n; i++) {
  cout << pre[i] - pre[i - 1] << ' ';
 }
 cout << endl;
}