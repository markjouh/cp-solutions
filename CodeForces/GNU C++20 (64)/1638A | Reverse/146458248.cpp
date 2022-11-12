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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) {
            cin >> x;
        }
        int id1 = 0, id2;
        while (id1 < n && id1 + 1 == a[id1]) {
            id1++;
        }
        id2 = id1;
        while (id2 < n && a[id2] != id1 + 1) {
            id2++;
        }
        reverse(a.bg + id1, a.bg + id2 + 1);
        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}