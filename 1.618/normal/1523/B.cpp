/*


Q.E.D.

start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

void solve() {
  int n, a;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a);
  printf("%d\n", n / 2 * 6);
  for (int i = 1; i <= n; i += 2) {
    printf("1 %d %d\n", i, i + 1);
    printf("2 %d %d\n", i, i + 1);
    printf("1 %d %d\n", i, i + 1);
    printf("2 %d %d\n", i, i + 1);
    printf("1 %d %d\n", i, i + 1);
    printf("2 %d %d\n", i, i + 1);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}