#include <bits/stdc++.h>
using namespace std;
 
void run_case() {
 int n, illegal;
 cin >> n >> illegal;
 vector<int> v(n);
 for (int &x : v) {
  cin >> x;
 }
 for (int i = 0; i < n; i++) {
  int sum = 0;
  bool flag = true;
  for (int x : v) {
   sum += x;
   if (sum == illegal) {
    flag = false;
    break;
   }
  }
  if (flag) {
   cout << "YES" << '\n';
   for (int x : v) {
    cout << x << ' ';
   }
   cout << '\n';
   return;
  }
  v.insert(v.begin(), v.back());
  v.pop_back();
 }
 cout << "NO" << '\n';
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  run_case();
 }
}