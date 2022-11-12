#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, h;
  cin >> n >> h;
  vector<int> weapons(n);
  for (int &x : weapons) {
   cin >> x;
  }
  sort(weapons.begin(), weapons.end(), greater<int>());
  int ans = h / (weapons[0] + weapons[1]) * 2;
  h -= ans / 2 * (weapons[0] + weapons[1]);
  if (h > 0) {
   h -= weapons[0];
   ans++;
  }
  if (h > 0) {
   h -= weapons[1];
   ans++;
  }
  cout << ans << '\n';
 }
}