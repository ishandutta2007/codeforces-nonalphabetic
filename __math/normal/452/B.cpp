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
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template<class T> ll mod_pow(T a, T n, T mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}

double SQ(int x) {
	return x * x;
}

double len(vector<Pii>& p) {
	double ret = 0;
	FOR(i, 3) {
		Pii a = p[i], b = p[i + 1];
		double x = SQ(a.first - b.first);
		double y = SQ(a.second - b.second);
		ret += sqrt(x + y);
	}
	return ret;
}

vector<Pii> solve(int n, int m) {
	if (n > m) {
		auto A = solve(m, n);
		vector<Pii> ret;
		FOR(i, 4) ret.emplace_back(A[i].second, A[i].first);
		return ret;
	}
	if (n == 0) {
		vector<Pii> ret;
		ret.emplace_back(0, 1);
		ret.emplace_back(0, m);
		ret.emplace_back(0, 0);
		ret.emplace_back(0, m - 1);

		return ret;
	} else {
		vector<Pii> X;
		X.emplace_back(0, 0);
		X.emplace_back(n, m);
		X.emplace_back(n, 0);
		X.emplace_back(0, m);

		vector<Pii> Y;
		Y.emplace_back(1, 0);
		Y.emplace_back(n, m);
		Y.emplace_back(0, 0);
		Y.emplace_back(n - 1, m);

		double lenx = len(X);
		double leny = len(Y);

		if (lenx > leny) {
			return X;
		} else {
			return Y;
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	auto ans = solve(n, m);

	FOR(i, 4) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}