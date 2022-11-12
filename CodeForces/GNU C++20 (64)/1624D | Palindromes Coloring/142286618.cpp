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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> ct(26);
    FOR(i, n) {
      ct[s[i]-'a']++;
    }
    int pairs = 0, odd = 0;
    FOR(i, 26) {
      pairs += ct[i]/2;
      odd += ct[i]%2;
    }
    odd += pairs%k*2;
    cout << (pairs/k*2 + (odd >= k)) << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/