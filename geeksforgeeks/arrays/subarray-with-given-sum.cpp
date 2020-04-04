/*
HINT:: Try solving it using sliding window approach
*/

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0)
#define f(i,a,b) for(i=a;i<=b;i++)
using namespace std;
#define ll long long
ll int n,i,a[10000001],t,sum, st, en, x;
bool found;
int main()
{    fast;
    cin>>t;
    while(t--)
    { cin>>n>>x;
        sum=0;
        st = en = -1;
    
     f(i,1,n) cin>>a[i];
     
     found = false;
     
     f(i,1,n) {
         
         if (a[i] > x) {
             sum = 0;
             st = -1;
             en = -1;
             continue;
         }
         
         sum+=a[i];

         en = i;
         if (st == -1) {
             st = i;
         }
         if (sum == x) {
             found = true;
         } else if (a[i] == x) {
             st = i;
             found = true;
         } else if (sum > x){
             while (sum > x && st < en) {
                 sum-=a[st++];
                 if (sum == x) {
                     found = true;
                 }
             }
         }
         
         if (found) {
             break;
         }
     }
     
     if (found) {
         cout<<st<<" "<<en<<"\n";
     } else {
         cout<<"-1\n";
     }
   }    

  return 0;
}