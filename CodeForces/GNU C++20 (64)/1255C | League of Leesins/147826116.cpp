#include <bits/stdc++.h>
using namespace std;
 
#define pf push_front
#define pb push_back
#define rf pop_front
#define rb pop_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define per(i,a,b) for (int i = b-1; i >= a; i--)
 
pair<int,int> sp(int a, int b) {
  return pair<int, int>{min(a,b), max(a,b)};
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // First start with an side element (occurrence 1)
  // Then, find an element adjacent to our first element (occurrence 2, in a triple with ans[0])
 
  // For the rest of the n-2 elements, we need to find triple with the last and second to last
  // elements in ans, and with the third element not being the third to back element (if exists)
 
  // For last part, map<pair<int, int>, vector<int>> with sorted pairs
  // For each of our n-2 operations, if sz(map[pair]) == 1, then just get the third value
  // Otherwise, get the one with third value not equal to third to back
 
  int n;
  cin >> n;
 
  vector<vector<int>> adj(n+1);
  vector<int> occur(n+1);
  map<pair<int,int>, vector<int>> mp;
 
  rep(i,0,n-2) {
    vector<int> cur(3);
    rep(j,0,3) {
      cin >> cur[j];
    }
    adj[cur[0]].pb(cur[1]);
    adj[cur[0]].pb(cur[2]);
    adj[cur[1]].pb(cur[0]);
    adj[cur[1]].pb(cur[2]);
    adj[cur[2]].pb(cur[0]);
    adj[cur[2]].pb(cur[1]);
    occur[cur[0]]++;
    occur[cur[1]]++;
    occur[cur[2]]++;
    mp[sp(cur[0],cur[1])].pb(cur[2]);
    mp[sp(cur[0],cur[2])].pb(cur[1]);
    mp[sp(cur[1],cur[2])].pb(cur[0]);
  }
 
  vector<int> ans;
 
  rep(i,1,n+1) {
    if (occur[i] == 1) {
      ans.pb(i);
      break;
    }
  }
  for (int x : adj[ans.back()]) {
    if (occur[x] == 2) {
      ans.pb(x);
      break;
    }
  }
  rep(i,0,n-2) {
    auto p = sp(ans[sz(ans)-1], ans[sz(ans)-2]);
    if (sz(mp[p]) == 1) {
      ans.pb(mp[p][0]);
    } else {
      ans.pb((mp[p][0] == ans[sz(ans)-3] ? mp[p][1] : mp[p][0]));
    }
  }
 
  rep(i,0,n) {
    cout << ans[i] << " \n"[i == n-1];
  }
}