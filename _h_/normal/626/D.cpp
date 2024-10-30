#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;
const ll inf = 1LL<<60;
const ld eps = 1e-14;

int main(){
	int n;
	cin >> n;
	vi a(n);
	for(int &x : a) cin >> x;
	sort(allof(a));
	ld ans = 0;
	vl cd(5000), sum(5001);
	rep(i,0,n) rep(j,0,i) cd[a[i]-a[j]]++;
	rep(i,0,5000) sum[i+1] = sum[i] + cd[i];
	rep(d,0,5000)
		rep(d0,0,d) ans += (ld)cd[d0]*cd[d]*sum[d-d0];
	cout.precision(15);
	cout << ans/pow(n*(n-1.)/2,3) << endl;
}