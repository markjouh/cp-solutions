#include <bits/stdc++.h>
using namespace std;
 
pair<int, int> arr[105];
int delays[105];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
   cin >> arr[i].first >> arr[i].second;
  }
  for (int i = 1; i <= n; i++) {
   cin >> delays[i];
  }
  int time = arr[0].second;
  for (int i = 1; i <= n; i++) {
   time += arr[i].first - arr[i - 1].second + delays[i];
   if (i != n) {
    time += (arr[i].second - arr[i].first + 1) / 2;
    time = max(time, arr[i].second);
   }
  }
  cout << time << '\n';
 }
}