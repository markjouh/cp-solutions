#include <bits/stdc++.h>
using namespace std;
 
multiset<int> s;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 long long hp = 0, potions = 0;
 for (int i = 0; i < n; i++) {
  int a;
  cin >> a;
  if (hp + a >= 0) {
   hp += a;
   potions++;
   s.insert(a);
  } else if (!s.empty() && a > *s.begin()) {
   hp += abs(*s.begin()) - abs(a);
   s.erase(s.begin());
   s.insert(a);
  }
 }
 cout << potions << '\n';
}