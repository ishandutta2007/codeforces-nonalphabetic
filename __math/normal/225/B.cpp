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
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

ll s,k;

ll a[10000];

int main(){

	cin>>s>>k;

	ll current = 2;
	int i = 2;
	a[0] = a[1] = 1;
	while(current <= 10000000000){
		a[i] = current;
		current *= 2;
		if(i >= k) current -= a[i - k];
		i++;
	}

	vector<ll> ans;
	while(s > 0){
		int id = lower_bound(a,a+i,s) - a;
		if(a[id] > s) id--;
		ll val = a[id];
		s -= val;
		ans.push_back(val);
	}

	ans.push_back(0);

	cout << sz(ans) << endl;

	FOR(i,sz(ans)){
		cout << ans[i];
		if(i==sz(ans)-1) cout << endl;
		else cout << " ";
	}

	return 0;
}