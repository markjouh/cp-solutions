#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e9 + 7;
 
namespace modular_operations {
 long long madd(long long a, long long b) {
   return (a + b) % M;
 }
 long long msub(long long a, long long b) {
   return (((a - b) % M) + M) % M;
 }
 long long mmul(long long a, long long b) {
   return ((a % M) * (b % M)) % M;
 }
 long long mpow(long long base, long long exp) {
   long long res = 1;
   while (exp) {
  if (exp % 2 == 1){
   res = (res * base) % M;
  }
  exp >>= 1;
  base = (base * base) % M;
   }
   return res;
 }
 long long minv(long long base) {
   return mpow(base, M - 2);
 }
 long long mdiv(long long a, long long b) {
   return mmul(a, minv(b));
 }
 long long choose(long long n, long long k) {
  long long res = 1;
  for (long long i = 0; i < k; i++) {
   res = res * (n - i) % M * minv(i + 1) % M;
  }
  return res;
 }
}
 
using namespace modular_operations;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int k;
 cin >> k;
 long long children = (1ll << k) - 2;
 long long res = mpow(4, children);
 res = mmul(res, 6);
 cout << res << '\n';
}
 
/*
 Read the problem statement carefully
 Think about the problem in different ways
*/