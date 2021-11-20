#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200000;
int n,p,q;
ll a[N+5],b[N+5],c[N+5];
map <ll,ll> mp;
struct node
{ll val[N+5],w[N+5];
int d[N+5],sz;
inline int find(ll x)
{int l=1,r=sz;
while (l<=r)
{int mid=(l+r)>>1;
if (val[mid]<=x) {l=mid+1;}
else {r=mid-1;}
}
return r;
}
inline void init()
{for (int i=1;i<=sz;i++) w[i]=val[i];
sort(val+1,val+sz+1);
int tp=sz;
sz=unique(val+1,val+sz+1)-val-1;
for (int i=1;i<=tp;i++) d[i]=find(w[i]);
return;
}
}A,B,C;
struct BIT
{int t[N+5],sz;
inline void init()
{memset(t,0,sizeof(t));}
inline void add(int x)
{while (x<=sz)
{t[x]++;x+=(x&(-x));}
}
inline void del(int x)
{while (x<=sz)
{t[x]--;x+=(x&(-x));}
}
inline int q(int x)
{int s=0;
while (x)
{s+=t[x];x-=(x&(-x));}
return s;
}
}T;
inline ll cal(ll val)
{if (mp.find(val)!=mp.end()) return mp[val];
int i,j;
ll res=0;
//case 1
T.sz=A.sz;T.init();
int p1=1,p2=0;
for (i=1;i<=n-p+1;i++)
{int l=i+p,r=n-q+1;
if (l>r) continue;
while (p2+1<=r) {p2++;T.add(A.d[p2]);}
while (p1<l) {T.del(A.d[p1]);p1++;}
res+=T.q(A.find(val-a[n]-(a[i-1]-b[i-1]+b[i+p-1]-a[i+p-1])));
}
//case 2
T.sz=B.sz;T.init();
p1=1,p2=0;
for (i=1;i<=n-p+1;i++)
{int l=i+1,r=min(i+p-1,n-q+1);
if (l>r) continue;
while (p2+1<=r) {p2++;T.add(B.d[p2]);}
while (p1<l) {T.del(B.d[p1]);p1++;}
res+=T.q(B.find(val-a[n]-(a[i-1]-b[i-1]+c[i+p-1]-b[i+p-1])));
}
//case 3
T.sz=A.sz;T.init();
p1=1,p2=0;
for (i=1;i<=n-p+1;i++)
{int l=max(1,i+p-q),r=min(i,n-q+1);
if (l>r) continue;
while (p2+1<=r) {p2++;T.add(A.d[p2]);}
while (p1<l) {T.del(A.d[p1]);p1++;}
res+=T.q(A.find(val-a[n]-(b[i-1]-c[i-1]+c[i+p-1]-b[i+p-1])));
}
//case 4
T.sz=C.sz;T.init();
p1=1,p2=0;
for (i=1;i<=n-p+1;i++)
{int l=1+max(0,i-q),r=i+p-q-1;
if (l>r) continue;
while (p2+1<=r) {p2++;T.add(C.d[p2]);}
while (p1<l) {T.del(C.d[p1]);p1++;}
res+=T.q(C.find(val-a[n]-(b[i-1]-c[i-1]+b[i+p-1]-a[i+p-1])));
}
//case 5
T.sz=A.sz;T.init();
p1=1,p2=0;
for (i=1;i<=n-p+1;i++)
{int l=1,r=i-q;
if (l>r) continue;
while (p2+1<=r) {p2++;T.add(A.d[p2]);}
while (p1<l) {T.del(A.d[p1]);p1++;}
res+=T.q(A.find(val-a[n]-(a[i-1]-b[i-1]+b[i+p-1]-a[i+p-1])));
}
mp[val]=res;
return res;
}
inline ll solve(ll tar)
{ll l=n,r=c[n];
while (l<=r)
{ll mid=(l+r)>>1ll;
if (cal(mid)<tar) {l=mid+1;}
else {r=mid-1;}
}
return l;
}
int main (){
	int i,j;
	scanf ("%d%d%d",&n,&p,&q);
	p=min(p,n);q=min(q,n);
	if (p>q) swap(p,q);
	for (i=1;i<=n;i++)
	{int x,y,z;
	scanf ("%d%d%d",&x,&y,&z);
	a[i]=a[i-1]+x;
	b[i]=b[i-1]+y;
	c[i]=c[i-1]+z;
	}
	A.sz=B.sz=C.sz=n-q+1;
	for (i=1;i<=n-q+1;i++)
	{A.val[i]=a[i-1]-b[i-1]+b[i+q-1]-a[i+q-1];
	B.val[i]=b[i-1]-c[i-1]+b[i+q-1]-a[i+q-1];
	C.val[i]=a[i-1]-b[i-1]+c[i+q-1]-b[i+q-1];
	}
	A.init();B.init();C.init();
	ll tot=1ll*(n-p+1)*(n-q+1);
	ll ans=solve((tot+1)/2ll)+solve((tot+2)/2ll);
	printf ("%lld.",ans/2ll);
	if (ans&1) {puts("5");}
	else {puts("0");}
	return 0;
}
