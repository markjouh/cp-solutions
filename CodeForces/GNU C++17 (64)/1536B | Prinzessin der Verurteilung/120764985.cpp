#include <bits/stdc++.h>
using namespace std;
 
vector<char> nextstr(vector<char> v) {
 int idx = v.size() - 1;
 while (idx >= 0) {
  if (v[idx] != 'z') {
   v[idx] = v[idx] + 1;
   return v;
  } else {
   v[idx] = 'a';
   if (idx == 0) {
    v.push_back('a');
    return v;
   }
  }
  idx--;
 }
 return {};
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  string s;
  cin >> n >> s;
  vector<char> str(n), ans = {'a'};
  for (int i = 0; i < n; i++) str[i] = s[i];
  while (search(begin(str), end(str), begin(ans), end(ans)) != end(str)) {
   ans = nextstr(ans);
  }
  for (auto x : ans) cout << x;
  cout << '\n';
 }
}