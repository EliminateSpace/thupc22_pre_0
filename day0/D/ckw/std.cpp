#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define swp(x,y) ans.push_back(make_pair(x,y))
using namespace std;
int inn() { int x;scanf("%d",&x);return x; }
const int N=100010;int p[N],vis[N];vector<pair<int,int> > ans;
int main()
{
	int n=inn(),tot=0;rep(i,1,n) vis[i]=((p[i]=inn())==i);
	rep(i,1,n) if(!vis[i])
	{
		int j=i;while(p[j]^i) vis[j]=1,swp(j,n+1),j=p[j];
		vis[j]=1,swp(j,n+2),swp(i,n+2),swp(j,n+1),tot^=1;
	}
	if(tot) swp(n+1,n+2);
	if(!ans.size()) printf("0 0\n");
	else{
		printf("2 %d\n",(int)ans.size());
		for(int i=0;i<(int)ans.size();i++)
			printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
