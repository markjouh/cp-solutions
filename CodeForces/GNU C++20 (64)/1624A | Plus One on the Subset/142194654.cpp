#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    set<int> st;
    FOR(i, n) {
      int x;
      cin >> x;
      st.insert(x);
    }
    cout << *st.rbegin()-*st.begin() << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/