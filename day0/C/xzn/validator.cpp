//#define Test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
int n,t_m,t_c; 
int a[Nmax],b[Nmax],c[Nmax];
int main()
{
    #ifdef Test
    #endif
    scanf("%d%d%d",&n,&t_m,&t_c);
    assert(n>=1 && n<=200000);
    assert(t_m>=1 && t_m<=200000);
    assert(t_c>=1 && t_c<=200000);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        assert(a[i]>=1 && a[i]<=1000000000);
        assert(b[i]>=1 && b[i]<=1000000000);
        assert(c[i]>=1 && c[i]<=1000000000);
        assert(a[i]<b[i] && b[i]<c[i]);
    }
    return 0;
}


