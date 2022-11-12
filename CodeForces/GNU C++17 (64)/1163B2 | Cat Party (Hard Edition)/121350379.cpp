#include <bits/stdc++.h>
using namespace std;
 
// colorcnt is the number of appearances of a color (index)
// cnt is the number of colors with cnt idx
// we decrease cnt - 1 each time because 1 value goes up to it + 1
 
int cur, mx, ans;
int colors[100005], cnt[100005];
 
bool check(int i) {
 if (cnt[1] == i) return true;
 if (cnt[i] == 1) return true;
 if (cnt[1] == 1 && cnt[mx] * mx == i - 1) return true;
 if (cnt[mx - 1] * (mx - 1) == i - mx && cnt[mx] == 1) return true;
 return false;
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n;
 cin >> n;
 for (int i = 1; i <= n; i++) {
  cin >> cur;
  cnt[colors[cur]]--;
  colors[cur]++;
  cnt[colors[cur]]++;
  mx = max(mx, colors[cur]);
  if (check(i)) {
   ans = i;
  }
 }
 cout << ans << '\n';
}