#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
vector<int> solve(int a, int b, int req_a, int req_b) {
    vector<int> res;
    for (int i = 0; i <= min(a, req_a); i++) { // Place i a's in the correct spots
        int breaks = 0;
        int A = a, B = b, req_B = req_b;
 
        A -= i; // i A's go to a spots
        // req_A -= i;
 
        req_B -= A; // Remaining A's go to b spots
        breaks += A; // These count as breaks
 
        if (req_B < 0) { // There might not be enough b spots
           continue;
        }
 
        B -= req_B; // Fill in the rest of the b spots
        breaks += B; // The remaining B's go to incorrect spots
 
        res.push_back(breaks);
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;
        vector<int> res1 = solve(a, b, (a + b + 1) / 2, (a + b) / 2);
        vector<int> res2 = solve(a, b, (a + b) / 2, (a + b + 1) / 2);
        res1.insert(res1.end(), all(res2));
        sort(all(res1));
        res1.resize(unique(all(res1)) - res1.begin());
        cout << sz(res1) << '\n';
        for (int i = 0; i < sz(res1); i++) {
            cout << res1[i] << ' ';
        }
        cout << '\n';
    }
}