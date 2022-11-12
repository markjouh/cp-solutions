#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, k;
  cin >> n >> k;
  vector<int> mice(k);
  for (int& x : mice) {
   cin >> x;
  }
  sort(mice.begin(), mice.end(), greater<int>());
  int time = 0, res = 0;
  for (int i = 0; i < mice.size(); i++) {
   if (mice[i] > time) {
    time += n - mice[i];
    res++;
   }
  }
  cout << res << '\n';
 }
}