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
    int last = 3;
    for (int i = 0; i < n; i++) {
      int c = s[i]-'0';
      bool add = c+1 != last;
      cout << add;
      last = c+add;
    }
    cout << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/