#include <bits/stdc++.h>
using namespace std;
 
int ceildiv(int x, int y) {
 return (x + y - 1) / y;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 if (n % 2) {
  cout << 2 * (n / 2 + 1) * (n / 2 + 2) << '\n';
 } else {
  cout << (n / 2 + 1) * (n / 2 + 1) << '\n';
 }
}