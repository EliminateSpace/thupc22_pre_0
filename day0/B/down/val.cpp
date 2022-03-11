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
int a[110];char s[100];
int main()
{
	rep(i,1,3)
	{
		debug(i)ln;
		sprintf(s,"%d.in",i);
		freopen(s,"r",stdin);
		int n=inn(),x=inn(),T=inn(),ds=0;
		assert(n>=1&&n<=100&&T>=1&&T<=100&&x>=1&&x<=n);
		rep(q,1,n)
		{
			int d=inn();ds+=d;
			assert(d>=1&&d<=n);
			rep(j,1,n) a[j]=0;
			rep(j,1,d)
			{
				int y=inn();
				assert(y>=1&&y<=n);
				assert(!a[y]);
				a[y]=1;
			}
		}
		fclose(stdin);
	}
	return 0;
}
