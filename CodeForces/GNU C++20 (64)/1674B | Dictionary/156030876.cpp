#include <bits/stdc++.h>
using namespace std;
 
#define SZ(x) (int)size(x)
#define ALL(x) begin(x), end(x)
 
int main() {
  vector<string> words;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i != j) {
        string cur;
        cur += (char)(i+'a');
        cur += (char)(j+'a');
        words.push_back(cur);
      }
    }
  }
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    cout << find(ALL(words), s) - begin(words) + 1 << '\n';
  }
}