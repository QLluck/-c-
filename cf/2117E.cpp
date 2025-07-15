#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int a[N]={0};
int b[N]={0};


void solve()
{
   int n;
   cin>>n;
   for(int i =1;i<=n;i++)cin>>a[i];
   for(int i =1;i<=n;i++)cin>>b[i];
   int ans = 0 ;
   int flag =0 ;
   map<int,int>mp[2];
   for(int i =n ;i >=1;i--)
   {   
    if(a[i]==b[i])
    {
        cout<<i<<'\n';
        return;
    }
        int a1 =0 ;
        if(mp[flag][a[i]]&&mp[flag][a[i]]>i+1)a1= max(i ,a1 );
         if(mp[!flag][a[i]])a1=max(i,a1);
        

        
        
        ans =max(a1,ans);
                int b1 =0 ;
       
        if(mp[!flag][b[i]]&&mp[!flag][b[i]]>i+1)b1= max(i ,b1 );
         if(mp[flag][b[i]])b1=max(i,b1);
         ans =max(b1,ans);

        
        if(!mp[flag][a[i]])mp[flag][a[i]]=i ;
          if(!mp[!flag][b[i]])mp[!flag][b[i]]= i ;

          if(ans)
          {
            cout<<ans<<'\n';
            return;
          } 

         flag=!flag;

      

   }
   cout<<ans<<'\n';

}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
     int t;
     cin>>t;
     while(t--)
     solve();
}