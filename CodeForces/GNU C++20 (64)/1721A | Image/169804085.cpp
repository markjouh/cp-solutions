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
        set<char> st;
        for (int i = 0; i < 4; i++) {
            char c;
            cin >> c;
            st.insert(c);
        }
        cout << st.size() - 1 << '\n';
    }
}