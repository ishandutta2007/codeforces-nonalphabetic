#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
 
#define debug(format, ...) printf(format, __VA_ARGS__);

const ll MOD = (ll)1e9 + 7;

class modint {
  int v;
public:
  modint (): v(0) { }
  modint (ll v): v((v + MOD) % MOD) { }

  bool operator== (modint x) { return v == x.v; }
  bool operator!= (modint x) { return v != x.v; }

  modint operator+ (modint x) { return v + x.v; }
  modint operator- (modint x) { return v - x.v; }
  modint operator* (modint x) { return (ll)v * x.v; }
  modint operator/ (modint x) { return *this * x.inv(); }

  modint& operator+= (const modint x) { return *this = (*this + x); }
  modint& operator-= (const modint x) { return *this = (*this - x); }
  modint& operator*= (const modint x) { return *this = (*this * x); }
  modint& operator/= (const modint x) { return *this = (*this / x); }

  int operator* () { return v; }

  modint inv() {
    modint ret = 1, cur = v;
    int p = MOD - 2;
    while(p > 0) {
      if(p & 1) ret = ret * cur;
      cur = cur * cur;
      p >>= 1;
    }
    return ret;
  }
};

char S[5050];
int N;

int L[5050], R[5050];

int main() {
#ifdef IN_MY_COMPUTER
  freopen("a.in", "r", stdin);
#endif

  scanf("%s", S);
  N = strlen(S);

  for(int i = 0; i < N; i++) {
    L[i] = -1;
    for(int j = i, c = 0; j >= 0; j--) {
      c += (S[j] == '(') ? -1 : +1;
      if(c < 0) {
        L[i] = j;
        break;
      }
    }

    R[i] = N;
    for(int j = i, c = 0; j < N; j++) {
      c += (S[j] == ')') ? -1 : +1;
      if(c < 0) {
        R[i] = j;
        break;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      if((j - i + 1) % 2 == 0 && R[i] > j && L[j] < i) {
        ans += 1;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}