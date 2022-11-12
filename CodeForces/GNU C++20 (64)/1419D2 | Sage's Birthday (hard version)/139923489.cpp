#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> spheres(n);
 for (int &x : spheres)
 {
  cin >> x;
 }
 
 sort(spheres.begin(), spheres.end());
 int l = 0, r = n / 2 + n % 2;
 while (l + 1 < r)
 {
  int mid = l + (r - l) / 2;
  bool ok = true;
  for (int i = 0; i < mid; i++)
  {
   ok &= spheres[i] < spheres[n - mid - 1 + i] && spheres[i] < spheres[n - mid + i];
  }
  (ok ? l : r) = mid;
 }
 
 cout << l << '\n';
 for (int i = 0; i < l; i++)
 {
  cout << spheres[n - l - 1 + i] << ' ' << spheres[i]  << ' ';
 }
 cout << spheres[n - 1] << ' ';
 for (int i = l; i < n - l - 1; i++) {
  cout << spheres[i] << ' ';
 }
 cout << '\n';
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/