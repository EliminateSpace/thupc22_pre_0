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
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
const int N=1000010;const lint INF=1000000000000;
struct union_find{
	int fa[N];
	inline void init(int L,int R) { rep(i,L,R) fa[i]=i; }
	inline int find(int x) { return x!=fa[x]?fa[x]=find(fa[x]):x; }
	inline int merge(int x,int y) { if((x=find(x))!=(y=find(y))) return fa[x]=y,1;return 0; }
	inline int con(int x,int y) { return find(x)==find(y); }
}uf;
struct info{
	lint val;int fr;info(lint _val=INF,int _fr=0):val(_val),fr(_fr) { }
	inline bool operator<(const info &i)const{ return val<i.val; }
	inline info operator*(int x)const { info i=*this;i.val*=x;return i; }
	inline info operator/(int x)const { info i=*this;i.val/=x;return i; }
}ans[N],val;
struct msg{
	info mn1,mn2;msg(){}
	inline msg& operator+=(info v)
	{
		if(v.fr==mn1.fr) mn1.val=min(mn1.val,v.val);
		else if(v.fr==mn2.fr)
		{
			mn2.val=min(mn2.val,v.val);
			if(mn2.val<mn1.val) swap(mn1,mn2);
		}
		else{
			if(v.val<mn1.val) swap(v,mn1);
			if(v.val<mn2.val) swap(v,mn2);
		}
		return *this;
	}
	inline msg operator+(const info &v)const{ msg c=*this;c+=v;return c; }
	inline info not_fr(int b)const{ return mn1.fr!=b?mn1:mn2; }
	inline void show() { debug(mn1.val)sp,debug(mn1.fr)sp,debug(mn2.val)sp,debug(mn2.fr)ln; }
}v[N];int bel[N];lint Ans=0;pii a[1491899+100];
inline int boruvka(int L,int R,int c)
{
	rep(i,1,R) v[i]=msg();rep(i,L,R) bel[i]=uf.find(i),ans[i]=info();
	int x,b,d,cnt=0;rep(i,1,c) x=a[i].fir,v[a[i].sec]+=(info(x,bel[x]));
	rep(i,1,c)
	{
		x=a[i].fir,d=a[i].sec,b=bel[x];
		if((val=v[d].not_fr(b)).fr) ans[b]=min(ans[b],val/d*x);
	}
	rep(i,L,R) if(i==bel[i]&&ans[i].fr)
		if(uf.merge(i,ans[i].fr)) cnt++,Ans+=ans[i].val;
	return cnt;
}
int main()
{
//	freopen("data.in","r",stdin);
	int L,R,c=0;scanf("%d%d",&L,&R),uf.init(L,R);
	rep(i,1,R) for(int j=(L-1)/i*i+i;j<=R;j+=i) a[++c]=mp(j,i);
	for(int cnt=R-L+1;(cnt-=boruvka(L,R,c))>1;);
	return !printf("%lld\n",Ans);
}
