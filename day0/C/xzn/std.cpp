//#define Test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=2e5+7;
typedef long long ll;
int n,t_m,t_c; 
struct BIT
{
    int c[Nmax],size;

    inline int lowbit(int x)
    {
    	return x&(-x);
    }

    void update(int pos,int add)
    {
    //cout<<__LINE__<<endl;
    	while(pos<=size)
        {
    //cout<<__LINE__<<endl;
    //cout<<"pos:"<<pos<<" "<<endl;
    		c[pos]+=add,pos+=lowbit(pos);

        }
    }

    void clear(int pos)
    {
    	while(pos<=size)
    		c[pos]=0,pos+=lowbit(pos);
    }

    void init()
    {
        for(int i=0;i<=size;i++)
            c[i]=0;
		//for(int i=1;i<=size;i++)
			//update(i,1);
    }

    ll get_sum(int pos)
    {
    	ll ans=0;
    	while(pos)
    		ans+=c[pos],pos-=lowbit(pos);
    	return ans;
    }
    
    ll query(int l,int r)
    {
    	return get_sum(r)-get_sum(l-1);
    }
    
}bit;

struct Node{
    int size;
    ll val[Nmax];
    ll data[Nmax];
    int pos[Nmax];
    int find(ll x)
    {
        return upper_bound(val+1,val+size+1,x)-val-1;
    }
    void init()
    {
        for(int i=1;i<=size;i++)
            data[i]=val[i];
        int now=size;
        sort(val+1,val+1+size);
        size=unique(val+1,val+size+1)-val-1;
        for(int i=1;i<=now;i++)
            pos[i]=find(data[i]);
    }
}node[4];

ll a[Nmax],b[Nmax],c[Nmax];
map<ll,ll> mp;
ll check(ll val)
{
    if(mp.count(val))
        return mp[val];
    ll ans=0;

    bit.size=node[1].size;
    bit.init();
    int vl=1,vr=0;
    //cout<<__LINE__<<endl;
    for(int i=1;i<=n-t_m+1;i++)
    {
        int l=i+t_m,r=n-t_c+1;
        if(l>r)
            continue;
    //cout<<__LINE__<<endl;
        while(vr+1<=r)
        {
            vr++;
    //cout<<__LINE__<<endl;
            bit.update(node[1].pos[vr],1);
    //cout<<__LINE__<<endl;
        }
    //cout<<__LINE__<<endl;
        while(vl<l)
        {
            bit.update(node[1].pos[vl],-1);
            vl++;
        }
        ans+=bit.get_sum(node[1].find(val-a[n]-(a[i-1]-b[i-1]+b[i+t_m-1]-a[i+t_m-1])));
    }

    bit.size=node[2].size;
    bit.init();
    vl=1,vr=0;
    for(int i=1;i<=n-t_m+1;i++)
    {
        int l=i+1,r=min(i+t_m-1,n-t_c+1);
        if(l>r)
            continue;
    //cout<<__LINE__<<endl;
        while(vr+1<=r)
        {
            vr++;
            bit.update(node[2].pos[vr],1);
        }
    //cout<<__LINE__<<endl;
        while(vl<l)
        {
            bit.update(node[2].pos[vl],-1);
            vl++;
        }
        ans+=bit.get_sum(node[2].find(val-a[n]-(a[i-1]-b[i-1]+c[i+t_m-1]-b[i+t_m-1])));
    }
    
    bit.size=node[1].size;
    bit.init();
    vl=1,vr=0;
    for(int i=1;i<=n-t_m+1;i++)
    {
        int l=max(1,i+t_m-t_c),r=min(i,n-t_c+1);
        if(l>r)
            continue;
        while(vr+1<=r)
        {
            vr++;
            bit.update(node[1].pos[vr],1);
        }
        while(vl<l)
        {
            bit.update(node[1].pos[vl],-1);
            vl++;
        }
        ans+=bit.get_sum(node[1].find(val-a[n]-(b[i-1]-c[i-1]+c[i+t_m-1]-b[i+t_m-1])));
    }

    bit.size=node[3].size;
    bit.init();
    vl=1,vr=0;
    for(int i=1;i<=n-t_m+1;i++)
    {
        int l=max(1,i-t_c+1),r=i+t_m-t_c-1;
        if(l>r)
            continue;
        while(vr+1<=r)
        {
            vr++;
            bit.update(node[3].pos[vr],1);
        }
        while(vl<l)
        {
            bit.update(node[3].pos[vl],-1);
            vl++;
        }
        ans+=bit.get_sum(node[3].find(val-a[n]-(b[i-1]-c[i-1]+b[i+t_m-1]-a[i+t_m-1])));
    }

    bit.size=node[1].size;
    bit.init();
    vl=1,vr=0;
    for(int i=1;i<=n-t_m+1;i++)
    {
        int l=1,r=i-t_c;
        if(l>r)
            continue;
        while(vr+1<=r)
        {
            vr++;
            bit.update(node[1].pos[vr],1);
        }
        while(vl<l)
        {
            bit.update(node[1].pos[vl],-1);
            vl++;
        }
        ans+=bit.get_sum(node[1].find(val-a[n]-(a[i-1]-b[i-1]+b[i+t_m-1]-a[i+t_m-1])));
    }

    mp[val]=ans;
    return ans;
}
ll get(ll x)
{
    ll l=n,r=c[n];
    while(l<=r)
    {
        ll mid=(r-l)/2+l;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if(check(mid)<x)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}
int main()
{
    #ifdef Test
    #endif
    scanf("%d%d%d",&n,&t_m,&t_c);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        a[i]=a[i-1]+a[i];
        b[i]=b[i-1]+b[i];
        c[i]=c[i-1]+c[i];
    }
    t_m=min(t_m,n);
    t_c=min(t_c,n);
    if(t_m>t_c) swap(t_m,t_c);
    int N=n-t_c+1;
    for(int i=1;i<=3;i++)
        node[i].size=N;
    for(int i=1;i<=N;i++) 
    {
        node[1].val[i]=a[i-1]-b[i-1]+b[i+t_c-1]-a[i+t_c-1];
        node[2].val[i]=b[i-1]-c[i-1]+b[i+t_c-1]-a[i+t_c-1];
        node[3].val[i]=a[i-1]-b[i-1]+c[i+t_c-1]-b[i+t_c-1];
    }
    for(int i=1;i<=3;i++)
        node[i].init();
    ll sum=(ll)(n-t_m+1)*(n-t_c+1);
    //cout<<sum<<endl;
    double ans=(double)(get((sum+1)/2)+get((sum+2)/2))/2.0;
    printf("%.1lf\n",ans);
    
    return 0;
}


