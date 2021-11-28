#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
int inn() { int x;scanf("%d",&x);return x; }
char s[100];int p[100100];
int main()
{
	rep(i,1,60)
	{
		debug(i)ln;
		sprintf(s,"../data/%d.in",i),freopen(s,"r",stdin);
		int n=inn();rep(i,1,n) p[i]=inn();sort(p+1,p+n+1);
		rep(i,1,n) assert(p[i]==i);assert(n>=1&&n<=100000);
	}
	rep(i,1,1)
	{
		debug(i)ln;
		sprintf(s,"../down/%d.in",i),freopen(s,"r",stdin);
		int n=inn();rep(i,1,n) p[i]=inn();sort(p+1,p+n+1);
		rep(i,1,n) assert(p[i]==i);assert(n>=1&&n<=100000);
	}
	return 0;
}
