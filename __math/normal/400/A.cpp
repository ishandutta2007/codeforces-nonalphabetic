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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

string to_str(int x) {
	char buf[100];
	sprintf(buf, "%d", x);
	return buf;
}

int main(){
	int t;
	cin >> t;
	while (t--) {
		string buf;
		cin >> buf;
		vector<string> vs;
		for (int a = 1; a <= 12; a++) {
			if (12 % a != 0) continue;
			bool ok = false;
			FOR(col, 12 / a) {
				bool tmp = true;
				FOR(row, a) {
					if (buf[row * 12 / a + col] != 'X') tmp = false;
				}
				if (tmp)ok = true;
			}
			if (ok)vs.push_back(to_str(a) + "x" + to_str(12 / a));
		}
		printf("%d",sz(vs));
		FOR(i, sz(vs)) printf(" %s",vs[i].c_str());
		puts("");
	}

	return 0;
}