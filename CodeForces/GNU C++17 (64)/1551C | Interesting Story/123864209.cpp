#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<string> a(n);
  for (string &s : a) {
   cin >> s;
  }
  int ans = 0;
  for (char target = 'a'; target <= 'e'; target++) {
   vector<int> b;
   for (string s : a) {
    int cnt = 0;
    for (char c : s) {
     if (c == target) {
      cnt++;
     } else {
      cnt--;
     }
    }
    b.push_back(cnt);
   }
   sort(b.begin(), b.end(), greater<int>());
   int sum = 0, cur = 0;
   for (int x : b) {
    sum += x;
    if (sum > 0) {
     cur++;
    } else break;
   }
   ans = max(ans, cur);
  }
  cout << ans << '\n';
 }
}