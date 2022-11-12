#include <bits/stdc++.h>
using namespace std;
 
const string alph = "abcdefghijklmnopqrstuvwxyz";
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  deque<char> q;
  for (char c : s) {
   q.push_back(c);
  }
  string res;
  while (q.size() > 0) {
   if (q.front() > q.back()) {
    res += q.front();
    q.pop_front();
   } else {
    res += q.back();
    q.pop_back();
   }
  }
  reverse(res.begin(), res.end());
  cout << (res == alph.substr(0, res.size()) ? "YES" : "NO") << '\n';
 }
}