#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define p 998244353
#define lint long long
#define ull unsigned lint
#define db long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define gc getchar()
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
const int MXT=110,N=110;int At[MXT][N],Ban[MXT][N],d[N],g[N][N],inv[N];
inline void upd(int &x,int y) { (x+=y)>=p?(x-=p):0; }
inline int fast_pow(int x,int k,int ans=1) { for(;k;k>>=1) { if(k&1) ans=(lint)ans*x%p;x=(lint)x*x%p; } return ans; }
inline int get_At(int n,int s0,int T)
{
	At[0][s0]=1;
	rep(t,0,T-1)
	{
		int *now=At[t],*nxt=At[t+1],q;
		rep(x,1,n) if((q=now[x])&&d[x])
		{
			int v=(lint)q*inv[d[x]]%p,*gx=g[x];
			rep(i,1,d[x]) upd(nxt[gx[i]],v);
		}
	}
	return 0;
}
inline int get_Ban(int n,int x,int T)
{
	memset(Ban[0],0,(n+1)<<2),Ban[0][x]=1;
	rep(t,1,T)
	{
		int *now=Ban[t],*pre=Ban[t-1];
		rep(y,1,n) if(y^x)
		{
			lint v=0;int q=0,*gy=g[y];
			rep(i,1,d[y]) if((q=pre[gy[i]])) v+=q;
			now[y]=v%p*inv[d[y]]%p;
		}
		now[x]=0;
	}
	rep(t,1,T) rep(y,1,n) upd(Ban[t][y],Ban[t-1][y]);
	return 0;
}
inline int get_ans(int n,int T,int ans=0)
{
	rep(x,1,n)
	{
		get_Ban(n,x,T);
		rep(tp,0,T-1) if(At[tp][x])
		{
			int v=(lint)At[tp][x]*inv[d[x]]%p,y;
			rep(i,1,d[x]) y=g[x][i],ans=(ans+(lint)v*y%p*Ban[T-tp-1][y])%p;
		}
	}
	return ans;
}
int main()
{
	freopen("data.in","r",stdin);
	int n=inn(),s0=inn(),T=inn();rep(i,1,n) inv[i]=fast_pow(i,p-2);
	rep(i,1,n) { d[i]=inn();rep(j,1,d[i]) g[i][j]=inn(); }
	return get_At(n,s0,T),!printf("%d\n",get_ans(n,T));
}
