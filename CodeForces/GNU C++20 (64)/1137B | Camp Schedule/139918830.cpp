#include <bits/stdc++.h>
using namespace std;
 
bool uniform(string s)
{
 for (int i = 1; i < int(s.size()); i++)
 {
  if (s[i] != s[0])
  {
   return false;
  }
 }
 return true;
}
 
vector<int> prefix_function(string s)
{
 int n = s.size();
 vector<int> pi(n);
 for (int i = 1; i < n; i++)
 {
  int j = pi[i - 1];
  while (j > 0 && s[i] != s[j])
  {
   j = pi[j - 1];
  }
  if (s[i] == s[j])
  {
   j++;
  }
  pi[i] = j;
 }
 return pi;
}
 
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 string s, t;
 cin >> s >> t;
 if (uniform(t))
 {
  sort(s.begin(), s.end());
  cout << s << '\n';
  return 0;
 }
 int m = t.size();
 vector<int> pre_fn = prefix_function(t);
 int rm = pre_fn[m - 1];
 string T;
 for (int i = rm; i < m; i++) {
  T += t[i];
 }
 
 vector<int> ct(2);
 for (char c : s)
 {
  ct[c - '0']++;
 }
 
 for (char c : t)
 {
  if (ct[c - '0'])
  {
   cout << c;
   ct[c - '0']--;
  }
 }
 
 int added = int(T.size());
 while (added == int(T.size()))
 {
  added = 0;
  for (char c : T)
  {
   if (ct[c - '0'] > 0) {
    cout << c;
    ct[c - '0']--;
    added++;
   }
  }
 }
 
 cout << string(ct[0], '0');
 cout << string(ct[1], '1');
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/