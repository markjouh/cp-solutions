#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << 4 * (n + 1) - n << '\n';
    cout << "0 0\n0 1\n1 0\n1 1\n";
    int y = 1, x = 1;
    for (int i = 0; i < n; ++i) {
        cout << y << ' ' << x + 1 << '\n';
        cout << y + 1 << ' ' << x << '\n';
        cout << y + 1 << ' ' << x + 1 << '\n';
        ++y;
        ++x;
    }
}