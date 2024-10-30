#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

inline int fastMin(int x, int y) { return x > y ? y : x; }
inline int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
inline int fastAbs(int x) { return ((x >> (32 - 1))&(x ^ (-x))) ^ x; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int home[ten(5) + 1], away[ten(5) + 1];
int x[ten(5) + 1], y[ten(5) + 1];

int main() {
	int n;
	cin >> n;
	FOR(i, n) {
		cin >> x[i] >> y[i];
		home[x[i]]++;
		away[y[i]]++;
	}

	FOR(i, n) {
		printf("%d %d\n",n - 1 + home[y[i]], n - 1 - home[y[i]]);
	}

	return 0;
}