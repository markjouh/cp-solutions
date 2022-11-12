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
 
int q(int x, int y) {
  cout << "? " << x+1 << ' ' << y+1 << endl;
  int res;
  cin >> res;
  return res;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int id = 0;
  int ans[n];
  rep(i,1,n) {
    int a = q(i,id);
    int b = q(id,i);
    if (a > b) {
      ans[i] = a;
    } else {
      ans[id] = b;
      id = i;
    }
  }
  ans[id] = n;
  cout << "! ";
  rep(i,0,n) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}