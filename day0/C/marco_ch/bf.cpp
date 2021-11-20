#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200000;
int a[505][3],cnt=0,n,p,q;
ll tp[300005];
int main (){
	int i,j,k;
	scanf ("%d%d%d",&n,&p,&q);
	if (n>500) return 0; 
	p=min(p,n);q=min(q,n);
	for (i=1;i<=n;i++)
	{for (j=0;j<=2;j++)
	{scanf ("%d",&a[i][j]);}
	}
	for (i=1;i<=n-p+1;i++)
	{for (j=1;j<=n-q+1;j++)
	{cnt++;
	for (k=1;k<=n;k++)
	{int o=0;
	if (k>=i&&k<=i+p-1) o++;
	if (k>=j&&k<=j+q-1) o++;
	tp[cnt]+=a[k][o];
	}
	}
	}
	sort(tp+1,tp+cnt+1);
	ll ans=tp[(cnt+1)/2]+tp[(cnt+2)/2];
	printf ("%lld.",ans/2ll);
	if (ans&1) {puts("5");}
	else {puts("0");}
	return 0;
}
