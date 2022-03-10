//#define Test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
int n,t_m,t_c; 
ll a[Nmax],b[Nmax],c[Nmax];
ll ans[Nmax];
int main()
{
    #ifdef Test
    #endif
    scanf("%d%d%d",&n,&t_m,&t_c);
    if(n>1000)
        return 0;
    for(int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    int cnt=0;
    t_m=min(t_m,n);
    t_c=min(t_c,n);
    for(int i=1;i<=n-t_m+1;i++)
    {
        for(int j=1;j<=n-t_c+1;j++)
        {
            cnt++;
            ans[cnt]=0LL;
            for(int k=1;k<=n;k++)
            {
                if(k>=i && k<=i+t_m-1)
                {
                    if(k>=j && k<=j+t_c-1)
                        ans[cnt]+=c[k];
                    else 
                        ans[cnt]+=b[k];
                }
                else if(k>=j && k<=j+t_c-1)
                    ans[cnt]+=b[k];
                else ans[cnt]+=a[k];
            }
        }
    }
    sort(ans+1,ans+1+cnt);
    //for(int i=1;i<=cnt;i++)
        //printf("%lld\n",ans[i]);
    if(cnt&1)
        printf("%.1lf\n",(double)ans[cnt/2+1]);
    else
        printf("%.1lf\n",(double)(ans[cnt/2]+ans[cnt/2+1])/2.0);
    return 0;
}


