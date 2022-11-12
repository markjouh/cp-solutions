#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<ll> precomp = {1, 3, 40, 1260, 72576, 6652800, 889574400, 163459296000, 39520825344000, 12164510040883200};
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int n;
 cin >> n;
 cout << precomp[n / 2 - 1] << '\n';
}