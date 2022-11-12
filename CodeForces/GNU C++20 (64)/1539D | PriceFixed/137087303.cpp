#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<pair<long long, long long>> vp(n);
 for (int i = 0; i < n; ++i) {
  cin >> vp[i].second >> vp[i].first;
 }
 sort(vp.begin(), vp.end());
 long long ans = 0, ct = 0;
 int l = 0, r = n - 1;
 while (l <= r) {
  if (vp[l].first <= ct) {
   ans += vp[l].second;
   ct += vp[l].second;
   ++l;
  } else {
   long long get = min(vp[r].second, vp[l].first - ct);
   ans += get * 2;
   ct += get;
   vp[r].second -= get;
   if (vp[r].second == 0) {
    --r;
   }
  }
 }
 cout << ans << '\n';
}