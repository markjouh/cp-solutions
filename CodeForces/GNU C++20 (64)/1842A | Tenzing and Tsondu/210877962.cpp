#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
 
using namespace std;
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
#define VE vector
#define AR array
 
typedef long long LL;
typedef pair<int, int> PII;
 
void solve() {
    int N, M;
    cin >> N >> M;
    LL A = 0;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        A += X;
    }
    LL B = 0;
    for (int i = 0; i < M; i++) {
        int X;
        cin >> X;
        B += X;
    }
    if (A > B) {
        cout << "Tsondu\n";
    } else if (A == B) {
        cout << "Draw\n";
    } else {
        cout << "Tenzing\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}