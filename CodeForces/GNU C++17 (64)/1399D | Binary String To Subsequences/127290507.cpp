#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string s;
  cin >> n >> s;
  vector<int> zeroes, ones, res;
  int cnt = 0;
  for (char c : s) {
   int cur = 0;
   if (c == '0') {
    if (ones.empty()) {
     cnt++;
     cur = cnt;
     zeroes.push_back(cnt);
    } else {
     zeroes.push_back(ones.back());
     cur = ones.back();
     ones.pop_back();
    }
   }
   if (c == '1') {
    if (zeroes.empty()) {
     cnt++;
     cur = cnt;
     ones.push_back(cnt);
    } else {
     ones.push_back(zeroes.back());
     cur = zeroes.back();
     zeroes.pop_back();
    }
   }
   res.push_back(cur);
  }
  cout << cnt << '\n';
  for (int x : res) {
   cout << x << ' ';
  }
  cout << '\n';
 }
}