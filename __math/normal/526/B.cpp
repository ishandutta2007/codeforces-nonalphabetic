#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
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
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }

int n;
ll r[1 << 20];
ll ans = 0;
ll dfs(int v,int dep){
	if (dep == n) return 0;
	ll x = dfs(v * 2 + 1, dep + 1) + r[v * 2];
	ll y = dfs(v * 2 + 2, dep + 1) + r[v * 2 + 1];
	ll diff = abs(x - y);
	ans += diff;
	return max(x, y);
}

int main(){
	cin >> n;
	FOR(i, (1 << (n + 1)) - 2){
		cin >> r[i];
	}
	dfs(0,0);
	cout << ans << endl;
}