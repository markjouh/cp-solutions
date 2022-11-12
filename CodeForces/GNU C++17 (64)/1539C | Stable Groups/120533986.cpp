#include <bits/stdc++.h>
using namespace std;
 
long long ceildiv(long long x, long long y) {
 return (x + y - 1) / y;
}
 
int main() {
 long long n, k, x;
 cin >> n >> k >> x;
 vector<long long> students(n), gaps;
 for (long long &x : students) cin >> x;
 sort(students.begin(), students.end());
 int ans = 1;
 for (int i = 1; i < n; i++) {
  long long diff = students[i] - students[i - 1];
  if (diff > x) {
   ans++;
   if (x > 0) gaps.push_back(ceildiv(diff, x) - 1);
  }
 }
 sort(gaps.begin(), gaps.end());
 for (long long x : gaps) {
  if (x <= k && k > 0) {
   k -= x;
   ans--;
  } else break;
 }
 cout << ans << '\n';
}