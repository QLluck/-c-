#include<bits/stdc++.h>
const int N =5e5+7;
using namespace std ;
#define ll long long 
ll  arr[N]={0};

void solve()
{
     ll n,k;
     cin>>n>>k;
     ll ma = 0 ;
     ll mi =0 ;
     ll num=n*2;
    
  
 
    
        ll man= num ;
        ma += min(k-1,man);
        man -=(k-1);
        if(man>0)
        {
            if(man&1)ma+= (man/2)+1;
            else ma+=man/2;
        }
        ll min= num;
        //ll mi = 0 ;
        min -=(k-1);
        if(min>=0)
        {
            if(min&1)mi += min/2+1;
            else mi+=min/2;
        }
        cout<<mi<<' '<<ma<<'\n';


    

}


int main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  solve();
}