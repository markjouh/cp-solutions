#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 string s;
 cin >> n >> s;
 vector<int> digits(n);
 for (int i = 0; i < n; i++) {
  digits[i] = s[i] - '0';
 }
 bool ok = false;
 for (int i = 0; i <= n * 9; i++) {
  int sum = 0, cnt = 0;
  for (int j = 0; j < n; j++) {
   sum += digits[j];
   if (sum == i) {
    sum = 0;
    cnt++;
   }
  }
  ok |= sum == 0 && cnt > 1;
 }
 cout << (ok ? "YES" : "NO") << '\n';
}