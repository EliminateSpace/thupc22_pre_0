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
const int N=1000010;int fa[N];vector<pair<int,pii> > e;
inline int gcd(int x,int y) { return y?gcd(y,x%y):x; }
inline lint lcm(int x,int y) { return (lint)x/gcd(x,y)*y; }
inline int findf(int x) { return x!=fa[x]?fa[x]=findf(fa[x]):x; }
int main()
{
//	freopen("data.in","r",stdin);
	int L=inn(),R=inn();lint ans=0;
	rep(i,L,R) rep(j,i+1,R) e.pb(mp(lcm(i,j),mp(i,j)));
	sort(e.begin(),e.end());rep(i,L,R) fa[i]=i;
	Rep(i,e)
	{
		lint w=e[i].fir;int x=e[i].sec.fir,y=e[i].sec.sec;
		x=findf(x),y=findf(y);if(x!=y) ans+=w,fa[x]=y;
	}
	return !printf("%lld\n",ans);
}
