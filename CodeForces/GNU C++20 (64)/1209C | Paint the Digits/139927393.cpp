#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T;
 cin >> T;
 while (T--)
 {
  int n;
  string s;
  cin >> n >> s;
  vector<pair<int, int>> digits(n);
  for (int i = 0; i < n; i++)
  {
   digits[i] = {s[i] - '0', i};
  }
  sort(digits.begin(), digits.end());
 
  int last = -1, lim = 9;
  vector<int> res(n, 2);
  for (int i = 0; i < n; i++)
  {
   int id = digits[i].second;
   if (id > last && digits[i].first <= lim)
   {
    digits[i].first = -1;
    res[id] = 1;
    last = id;
   }
   else
   {
    lim = min(lim, digits[i].first);
   }
  }
 
  last = -1;
  bool ok = true;
  for (int i = 0; i < n; i++)
  {
   int id = digits[i].second;
   if (digits[i].first != -1)
   {
    ok &= id > last;
    last = id;
   }
  }
 
  if (!ok)
  {
   cout << '-';
  }
  else
  {
   for (int x : res)
   {
    cout << x;
   }
  }
  cout << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/