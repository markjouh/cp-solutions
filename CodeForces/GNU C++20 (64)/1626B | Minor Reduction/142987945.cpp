#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
 
    int val = 0, id = -1;
    for (int i = s.size()-2; i >= 0; i--) {
      int c = (s[i]-'0')+(s[i+1]-'0');
      if (c >= 10) {
        val = c;
        id = i;
        break;
      }
    }
 
    if (id != -1) {
      s[id+1] = '0'+val%10;
      val /= 10;
      s[id] = '0'+val;
    } else {
      int c = (s[0]-'0')+(s[1]-'0');
      s[0] = '0'+c;
      s.erase(s.begin()+1);
    }
 
    cout << s << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/