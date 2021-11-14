#include<bits/stdc++.h>
//#pragma gcc optimize(3)
#define gc getchar()
//char buf[100000],*buff = buf + 100000;
//#define gc ((buff == buf + 100000 ? (fread(buf,1,100000,stdin),buff = buf) : 0),*(buff++))
#define pc putchar
//char bfu[10000000],*bfuu = bfu;
//#define pc(x) (*(bfuu++) = x)
#define li long long
#define uli unsigned li
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define md int mid = l + r >> 1
#define ls q << 1
#define rs q << 1 | 1
#define ln ls,l,mid
#define rn rs,mid + 1,r
using namespace std;
//const int mo = 998244353;
//const int mo = 1000000007;
inline li read(){
	li x = 0;
	int y = 0,c = gc;
	while(c < '0' || c > '9') y = c,c = gc;
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = gc;
	return y == '-' ? -x : x;
}
inline void prt(li x){
	if(x >= 10) prt(x / 10);
	pc(x % 10 + '0');
}
inline void print(li x){
	if(x < 0) pc('-'),x = -x;
	prt(x);
}
inline void file(char *s){
	char c[50];
	sprintf(c,"%s.in",s);
	freopen(c,"r",stdin);
	sprintf(c,"%s.out",s);
	freopen(c,"w",stdout);
}
li s1 = 19260817,s2 = 23333333,s3 = 998244853,srd;
inline li rd(){
	return srd = (srd * s1 + s2 + rand()) % s3;
}
int n,a[100010],cnt,b[1000010][2],c[100010]; 
bool vis[100010];
set<pii > ss;
void wk(int x,int y){
	/*
	if(x > y) swap(x,y);
	assert(x > 0 && y > n && x != y);
	assert(ss.find(mp(x,y)) == ss.end());
	ss.insert(mp(x,y));
	*/
	swap(c[x],c[y]);
	b[++cnt][0] = x;b[cnt][1] = y;
}
int main(){
	srand(time(0));rd();
	//file("");
	int i,j,k;
	n = read();
	for(i = 1;i <= n;++i) a[i] = c[i] = read();
	c[n + 1] = n + 1;c[n + 2] = n + 2;
	for(i = 1;i <= n;++i) if(a[i] != i && !vis[i]){
		vis[i] = 1;
		wk(n + 1,i);
		for(j = a[i];j != i;j = a[j]){
			vis[j] = 1;
			if(a[j] != i) wk(n + 1,j);
			else{
				wk(n + 2,j);
				wk(n + 1,j);
				wk(n + 2,i);
			}
		}
	}
	if(c[n + 1] != n + 1) wk(n + 1,n + 2);
	for(i = 1;i <= n + 2;++i) assert(c[i] == i);
	if(!cnt){
		puts("0 0");
		return 0;
	}
	print(2);pc(' ');print(cnt);pc('\n');
	for(i = 1;i <= cnt;++i){
		print(b[i][0]);pc(' ');print(b[i][1]);pc('\n');
	}
	//fwrite(bfu,1,bfuu  - bfu,stdout);
	//cerr<<clock();
	return 0;
}


