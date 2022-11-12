#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
/*
  We could try checking if the current prefix if a rbs or palindrome using a counter and 2 deques respectively
*/
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s;
    cin >> n >> s;
    int ct = 0, rem = n;
 
    bool valid = true;
    int op = 0, cl = 0;
 
    char mid = ' ';
    deque<char> l, r;
 
    for (int i = 0; i < n; i++) {
      op += s[i] == '(';
      cl += s[i] == ')';
      valid &= op >= cl;
 
      r.push_front(s[i]);
      if (mid != ' ') {
        l.push_back(mid);
        mid = ' ';
      } else {
        mid = r.back();
        r.pop_back();
      }
 
      if ((op == cl && valid) || (l == r && l.size())) {
        ct++;
        rem = n - i - 1;
        valid = true, op = 0, cl = 0;
        l.clear(), mid = ' ', r.clear();
      }
    }
 
    cout << ct << ' ' << rem << '\n';
  }
}