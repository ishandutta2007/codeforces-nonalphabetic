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


using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int main(){
	int n; cin>>n;
	map<int,int> mp;
	FOR(i,n){
		int x; cin>>x;
		if(x == 0) continue;
		mp[x]++;
	}

	int ans = 0;
	for(map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it){
		if(it->second == 2) ans++;
		else if(it->second >= 3){
			ans = -1;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}