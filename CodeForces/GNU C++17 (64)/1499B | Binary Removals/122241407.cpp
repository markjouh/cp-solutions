#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  int a = s.find("11"), b = s.rfind("00");
  if (a != -1 && b != -1 && a < b) {
   cout << "NO" << '\n';
  } else {
   cout << "YES" << '\n';
  }
 }
}