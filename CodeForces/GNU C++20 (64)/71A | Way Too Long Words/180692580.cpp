#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
 
// submitting this to test out an edit I made to upcode, an automatic solution uploader
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        if (sz(s) <= 10) {
            cout << s << '\n';
        } else {
            cout << s.front() << sz(s) - 2 << s.back() << '\n';
        }
    }
}