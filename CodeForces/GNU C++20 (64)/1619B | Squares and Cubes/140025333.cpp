#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T;
 cin >> T;
 while (T--) {
  int n;
  cin >> n;
  int ans = 0;
  unordered_set<int> st;
  for (int i = 1; i * i <= n; i++)
  {
   ans++;
   st.insert(i * i);
  }
  for (int i = 1; i * i * i <= n; i++)
  {
   if (!st.count(i * i * i))
   {
    ans++;
   }
  }
  cout << ans << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/