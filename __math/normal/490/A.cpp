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
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int main(){
	int n; cin >> n;
	vector<int> t[3];
	FOR(i, n){
		int x; cin >> x;
		t[x - 1].push_back(i + 1);
	}
	vector<vector<int> > v;
	FOR(i, min(sz(t[0]), min(sz(t[1]), sz(t[2])))){
		vector<int> y = { t[0][i], t[1][i], t[2][i] };
		v.push_back(y);
	}
	cout << sz(v) << endl;
	for(auto i : v){
		FOR(j, 3) printf("%d%c",i[j],j==2?'\n':' ');
	}
}