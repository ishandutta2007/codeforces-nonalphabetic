#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	map<int,int> cnt;
	rep(i,0,n){
		int a;
		cin >> a;
		++cnt[a];
	}
	pii rek(-1,0);
	int ans;
	int m;
	cin >> m;
	vi bs(m), cs(m);
	rep(i,0,m) cin >> bs[i];
	rep(i,0,m) cin >> cs[i];
	rep(i,0,m){
		int b = bs[i], c = cs[i];
		pii cnd(cnt[b],cnt[c]);
		if(cnd > rek){
			rek = cnd;
			ans = i+1;
		}
	}
	cout << ans << endl;
}