#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  string s;
  cin >> n >> s;
  int cnt = count(s.begin(), s.end(), '0');
  if (cnt % 2 && cnt != 1) {
   cout << "ALICE" << '\n';
  } else {
   cout << "BOB" << '\n';
  }
 }
}
 
// B A B