#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);    
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s;
    cin >> n >> s;
    string res;
    res += s[0];
    if (s.size() > 1 && s[0] > s[1]) {
      for (int i = 1; i < n && s[i] <= s[i-1]; i++) {
        res += s[i];
      }
    }
    int m = res.size();
    for (int i = m-1; i >= 0; i--) {
      res += s[i];
    }
    cout << res << '\n';
  }
}
 
/*
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃Read the problem statement carefully┃
┃Think before implementing           ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/
 