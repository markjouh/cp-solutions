#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)
#define each(a, x) for (auto& x : a)
#define all(a) a.begin(), a.end()
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n; cin >> n;
 vector<int> nums(n);
 each(nums, x) cin >> x;
 if (n == 1) {
  cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
  cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
  cout << 1 << ' ' << 1 << '\n' << -nums[0];
  return 0;
 }
 cout << 1 << ' ' << n << '\n';
 rep(i, n - 1) cout << 1ll * nums[i] * -n << ' ';
 cout << 0 << '\n';
 cout << 1 << ' ' << n - 1 << '\n';
 rep(i, n - 1) cout << 1ll * nums[i] * (n - 1) << ' ';
 cout << '\n';
 cout << n << ' ' << n << '\n';
 cout << -nums[n - 1] << '\n';
}