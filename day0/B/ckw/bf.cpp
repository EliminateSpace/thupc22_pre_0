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
const int p=998244353,N=110;int las[N],s[N],d[N],g[N][N],inv[N],ans;
inline int fast_pow(int x,int k,int ans=1) { for(;k;k>>=1) { if(k&1) ans=(lint)ans*x%p;x=(lint)x*x%p; } return ans; }
inline int calc(int n,int T)
{
	int ans=0;
	rep(i,1,n) las[i]=-1;
	las[s[0]]=0;
	rep(i,1,T)
	{
		int x=s[i];
		if(las[x]>=0) ans+=s[las[x]+1];
		las[x]=i;
	}
	return ans;
}
inline int dfs(int t,int T,int n,int q)
{
	if(t==T) return ans=(ans+(lint)calc(n,T)*q)%p;
	int x=s[t];q=(lint)q*inv[d[x]]%p;
	rep(i,1,d[x]) s[t+1]=g[x][i],dfs(t+1,T,n,q);
	return 0;
}
int main()
{
	freopen("data.in","r",stdin);
	int n=inn(),s0=inn(),T=inn();s[0]=s0;
	rep(i,1,n) inv[i]=fast_pow(i,p-2);
	rep(i,1,n) { d[i]=inn();rep(j,1,d[i]) g[i][j]=inn(); }
	dfs(0,T,n,1);return !printf("%d\n",ans);
}
