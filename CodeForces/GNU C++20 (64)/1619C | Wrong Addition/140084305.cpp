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
  string A, S;
  cin >> A >> S;
  if (S.size() < A.size())
  {
   cout << -1 << '\n';
   continue;
  }
  vector<int> a, s;
  for (char c : A)
  {
   a.push_back(c - '0');
  }
  for (char c : S)
  {
   s.push_back(c - '0');
  }
  while (a.size() < s.size()) {
   a.insert(a.begin(), 0);
  }
 
  int n = a.size();
  string b, res;
  for (int i = 0; i < n && a.size() && s.size(); i++)
  {
   int have = a.back(), want = s.back();
   a.pop_back();
   s.pop_back();
   if (want < have)
   {
    want += 10;
    if (s.size() && s.back() == 1)
    {
     s.pop_back();
    }
   }
   b = to_string(want - have) + b;
   res = to_string(want) + res;
  }
  if (a.size())
  {
   while (a.size() && a.front() == 0)
   {
    a.erase(a.begin());
   }
   string add;
   for (int x : a)
   {
    add += x + '0';
   }
   res = add + res;
  }
  while (b.front() == '0') {
   b.erase(b.begin());
  }
  cout << (res == S ? b : "-1") << '\n';
  }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/