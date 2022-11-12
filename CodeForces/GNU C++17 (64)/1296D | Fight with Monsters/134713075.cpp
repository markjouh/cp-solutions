#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// cloudcloud
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr); 
 int n, a, b, k;
 cin >> n >> a >> b >> k;
 vector<int> cost;
 int ans = 0;
 for (int i = 0; i < n; ++i) {
  int h;
  cin >> h;
  int rem = h - h / (a + b) * (a + b); // hp left after all full turns end
  if (rem == 0) {
   cost.push_back((b + a - 1) / a);
  } else if (rem <= a) {
   ++ans;
  } else {
   cost.push_back((rem - 1) / a);
  }
 }
 sort(cost.begin(), cost.end());
 for (int i = 0; i < cost.size(); ++i) {
  if (k >= cost[i]) {
   k -= cost[i];
   ++ans;
  } else {
   break;
  }
 }
 cout << ans << '\n';
}