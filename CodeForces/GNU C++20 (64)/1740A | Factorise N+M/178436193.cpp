#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) (x).begin(), (x).end()
 
bool isprime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int M = 2;
        while (isprime(N+M) || !isprime(M)) {
            M++;
        }
        cout << M << '\n';
    }
}