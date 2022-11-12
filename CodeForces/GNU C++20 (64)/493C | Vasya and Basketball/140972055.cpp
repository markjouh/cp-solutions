#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 for (int &x : a) {
  cin >> x;
 }
 int m;
 cin >> m;
 vector<int> b(m);
 for (int &x : b) {
  cin >> x;
 }
 sort(all(a), greater<int>());
 sort(all(b), greater<int>());
 int resa = 0, resb = 0, id = 0;
 for (int i = 0; i < n; i++) {
  while (id < m && b[id] >= a[i]) {
   id++;
  }
  if (i - (id - 1) >= resa - resb) {
   resa = i + 1;
   resb = id;
  }
 }
 cout << resa + n * 2 << ':' << resb + m * 2 << '\n';
}