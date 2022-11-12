#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
 
// bnnbnn baabaa
// bnnbnn baabaa
 
// bnnbnn bnabaa baa
// 2 9
// 5 12
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "1\n1 2\n";
            continue;
        }
        cout << (n + 1) / 2 << '\n';
        vector<pair<int, int>> ans((n + 1) / 2);
        int h = n / 2;
        for (int i = 0; i < h; i++) {
            ans[i].first = i * 3 + 2;
        }
        for (int i = 0; i < h; i++) {
            ans[i].second = (i + h) * 3 + 3;
        }
        if (n % 2) {
            ans.back() = {h * 3 + 2, n * 3};
        }
        for (auto [f, s] : ans) {
            cout << f << ' ' << s << '\n';
        }
    }
}