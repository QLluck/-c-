#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
int me1[70]={0};
int me2[70]={0};
void f(ll x,int me[] )
{ 
    for(int i =61;i>=1;i--)
    {
         if(x&1)me[i]=1;
         else me[i]=0;
         x>>=1;
    }

}
void solve()
{
   ll x,y;
   cin>>x>>y;
   for(int i =1;i<=64 ;i++)
   {me1[i]=0;
    me2[i]=0;

   }
    f(x,me1);
    f(y,me2);

 
   
     ll sum = (ll)1<<60;
     //cout<<sum<<'\n';
     for(int i =1; i<=61 ;i++)
     {  //cout<<me1[i]<<' '<<me2[i]<<sum<<'\n';
        if(me1[i]==me2[i])x-=sum*me1[i];
        else break;
        sum>>=1;

     }


    
    
   
   cout<<x<<'\n';

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}