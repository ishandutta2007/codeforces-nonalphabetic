#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 2005
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int LEN = 100000;

struct fastio{
  int it,len;
  char s[LEN + 5];
  fastio(){
    it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    it = 0, len = fread(s,1,LEN,stdin);
    return len ? s[it++] : EOF;
  }
  bool notend(){
    char c;
    for(c = get();c == ' ' || c == '\n';c = get());
    if(it) it--;
    return c != EOF;
  }
  void put(char c){
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush(){
    fwrite(s,1,it,stdout);
  }
}buff,bufo;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll(){
  char c; ll res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char(){
  char c;
  for(c = buff.get();c == ' ' || c == '\n';c = buff.get());
  return c;
}

int T,k,n;
char s[maxn],t[maxn];
vector <P> ans;
void work(){
  ans.clear();
  for(int i = 1;i <= n;i++){
    if(s[i] != t[i]){
      int j;
      for(j = i + 1;j <= n;j++) if(s[j] == t[i]) break;
      ans.push_back(mp(i,j));
      reverse(s + i,s + j + 1);
    }
  }
  putint(ans.size(),'\n');
  for(int i = 0;i < (int)ans.size();i++){
    putint(ans[i].first,' ');
    putint(ans[i].second,'\n');
  }
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    scanf("%s",s + 1);
    int fir = n - k * 2 + 2;
    for(int i = 1;i <= fir / 2;i++) t[i] = '(';
    for(int i = fir / 2 + 1;i <= fir;i++) t[i] = ')';
    for(int i = fir + 1;i <= n;i += 2){
      t[i] = '(';
      t[i + 1] = ')';
    }
    work();
  }
  bufo.flush();
  return 0;
}