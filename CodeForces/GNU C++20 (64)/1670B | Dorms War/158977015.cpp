#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        string s;
        cin >> n >> s >> k;
        vector<bool> special(26);
        for (int i = 0; i < k; i++) {
            char c;
            cin >> c;
            special[c - 'a'] = 1;
        }
        // the answer for a given character is the distance from it to the next special character
        int id = n - 1;
        while (id >= 0 && !special[s[id] - 'a']) {
            id--;
        }
        int cnt = 1;
        vector<int> res(n);
        for (int i = id - 1; i >= 0; i--) {
            res[i] = cnt;
            if (special[s[i] - 'a']) {
                cnt = 0;
            }
            cnt++;
        }
        cout << *max_element(res.begin(), res.end()) << '\n';
    }   
}