#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define rb pop_back
#define bg begin()
#define ed end()
#define f first
#define s second
 
bool ok[1100];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 1100; i += 11) {
        for (int j = i; j < 1100; j += 111) {
            ok[j] = true;
        }
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int x;
        cin >> x;
        cout << (x > 1099 || ok[x] ? "YES\n" : "NO\n");
    }
}