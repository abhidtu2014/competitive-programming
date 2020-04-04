#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0)
#define f(i,a,b) for(i=a;i<=b;i++)
using namespace std;
#define ll long long
ll int n,i,a,t,sum;
int main()
{    fast;
    cin>>t;
   while(t--)
    { cin>>n;
     sum=0;
     f(i,1,n-1) {
         cin>>a;
         sum+=a;
     }
     n=(ll)(n*(n+1))>>1;
     cout<<(ll)(n-sum)<<"\n";
   }    

  return 0;
}