// mark zhou
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> ratings(n);
        for (int &x : ratings) {
            cin >> x;
        }
        string ok;
        cin >> ok;
        vector<pair<int, int>> disliked, liked;
        for (int i=0; i<n; i++) {
            (ok[i]=='1' ? liked : disliked).push_back({ratings[i], i});
        }
        int cur=n;
        vector<int> res(n);
        sort(liked.rbegin(), liked.rend());
        for (auto [f, s] : liked) {
            res[s]=cur--;
        }
        sort(disliked.rbegin(), disliked.rend());
        for (auto [f, s] : disliked) {
            res[s]=cur--;
        }
        for (int x : res) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}