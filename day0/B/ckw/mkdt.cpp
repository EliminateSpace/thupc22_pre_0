#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline int getn(int a,int b) { return (rand()*32767+rand())%(b-a+1)+a; }
int p[110];
int main()
{
	FILE *fsd=fopen("seed.txt","r");unsigned int sd,ccc;fscanf(fsd,"%u%u",&sd,&ccc);
	FILE *gsd=fopen("seed.txt","w");sd+=12321,ccc+=1;fprintf(gsd,"%u\n%u\n",sd,ccc);
	freopen("data.in","w",stdout),srand((unsigned int)time(0)+sd);
	int n=7,s0=1,T=7;printf("%d %d %d\n",n,s0,T);
	rep(i,1,n) p[i]=i;
	rep(i,1,n)
	{
		random_shuffle(p+1,p+n+1);
		int d=getn(1,n);printf("%d",d);
		rep(i,1,d) printf(" %d",p[i]);
		printf("\n");
	}
	return 0;
}
