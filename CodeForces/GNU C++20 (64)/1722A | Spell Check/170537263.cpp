#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;
        sort(all(s));
 
        string req = "Timur";
        sort(all(req));
 
        cout << (s == req ? "YES\n" : "NO\n");
    }
}