#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  long long n, k, x;
  string s;
  cin >> n >> k >> x >> s;
  x--;
  vector<long long> a;
  for (int i = 0; i < n; i++) {
   if (s[i] == '*') {
    int id = 0;
    while (i + id < n && s[i + id] == '*') {
     id++;
    }
    a.push_back(id);
    i += id - 1;
   }
  }
  int m = a.size();
  vector<long long> b(m);
  for (int i = m - 1; i >= 0; i--) {
   b[i] = x % (a[i] * k + 1);
   x /= (a[i] * k + 1);
  }
  int id = 0;
  for (int i = 0; i < n; i++) {
   if (s[i] == 'a') {
    cout << 'a';
   } else {
    while (i < n - 1 && s[i + 1] == '*') {
     i++;
    }
    for (int j = 0; j < b[id]; j++) {
     cout << 'b';
    }
    id++;
   }
  }
  cout << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/