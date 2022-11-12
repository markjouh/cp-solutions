#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 n *= 2;
 vector<int> people(n);
 for (int& x : people) {
  cin >> x;
 }
 sort(people.begin(), people.end());
 int ans = 1e9;
 for (int i = 0; i < n; i++) {
  for (int j = i + 1; j < n; j++) {
   vector<int> duo = people;
   duo.erase(duo.begin() + i);
   duo.erase(duo.begin() + j - 1);
   int cur = 0;
   for (int k = 0; k < n - 2; k += 2) {
    cur += abs(duo[k] - duo[k + 1]);
   }
   ans = min(ans, cur);
  }
 }
 cout << ans << '\n';
}