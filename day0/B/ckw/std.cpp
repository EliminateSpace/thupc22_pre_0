#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
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
inline int getg(int x,int y,int n,int t)
{
	rep(i,1,n) g[0][i]=(i==y);
	rep(i,
	rep(i,0,t-1)
	{
		int *cur=g[i],*nxt=g[i+1];
		rep(j,1,n) if(cur[j])
		{
			int *gj=g[j];
			rep(k,1,d[j]) if(gj[k]^x) gj[k]
		}
	}
	h[i]
}
int main()
{
	int n=inn(),s=inn(),t=inn();
	rep(i,1,n) { d[i]=inn();rep(j,1,d[i]) g[i][j]=inn(); }
	f[0][s]=1;
	rep(i,0,t-1)
	{
		int *cur=f[i],*nxt=f[i+1];
		rep(j,1,n) if(cur[j])
		{
			int *gj=g[j],v=(lint)cur[j]*inv[d[j]]%p;
			rep(k,1,d[j]) pls(nxt[gj[k]],v);
		}
	}
	rep(i,1,n) rep(j,1,d[i])
	{
		getg(i,g[i][j],n,t);
	}
}
