#include <bits/stdc++.h>
 
using namespace std;
 
void solveCase() {
  int n;
  string s;
  cin >> n >> s;
  int operations = 0;
  for (int i = 0; i < n; i += 2) {
    operations += s[i] != s[i + 1];
  }
  vector<int> pairs;
  for (int i = 0; i < n; i += 2) {
    if (s[i] == s[i + 1]) {
      pairs.push_back(s[i] - '0');
    }
  }
  int segments = 1;
  for (int i = 1; i < size(pairs); i++) {
    segments += pairs[i] != pairs[i - 1];
  }
  cout << operations << ' ' << segments << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cases;
  cin >> cases;
  while (cases--) {
    solveCase();
  }
}
 
/*
Firstly, the number of operations we need to perform is equal to the number of pairs a[i] = a[i + 1]
where i is even in string s.
 
The minimum number of segments can be solved separately. Since the value of pairs with a[i] != a[i + 1]
 
*/