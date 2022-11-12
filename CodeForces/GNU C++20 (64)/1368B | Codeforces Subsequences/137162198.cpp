#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
long long get(vector<int> ct) {
 long long res = 1;
 for (int x : ct) {
  res *= x;
 }
 return res;
}
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 long long k;
 cin >> k;
 vector<int> ct(10, 1);
 int id = 0;
 while (get(ct) < k) {
  ++ct[id++];
  if (id == 10) {
   id = 0;
  }
 }
 string cf = "codeforces", res;
 for (int i = 0; i < 10; ++i) {
  for (int j = 0; j < ct[i]; ++j) {
   res += cf[i];
  }
 }
 cout << res << '\n';
}