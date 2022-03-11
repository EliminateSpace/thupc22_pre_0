#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
char s[1000];
int main()
{
	rep(i,1,11)
	{
		sprintf(s,"%d.in",i);
		FILE *f=fopen(s,"r");
		int l,r;fscanf(f,"%d%d",&l,&r);
		assert(1<=l&&l<=r&&r<=1000000&&r-l<=100000);
	}
	cerr<<"checked"<<endl;
}