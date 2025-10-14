#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 5e5+7;
int ans[N];
int b[N];
stack<int >a[5];
void solve()
{
   int n;
   cin>>n;
   int it = 0;
   for(int i=1;i<=n;i++)
   {
    int a1 ;
    cin>>a1;
    b[i]=a1;
    a[(a1%4)].push(i);
   }
   int n0 = a[0].size();
   int n1 = a[1].size();
   int n2 = a[2].size();
   int n3 = a[3].size();

   int flag=0;

  
  
  
     while(a[3].size()&&a[1].size())
     {
        // int f =0 ;
        if(a[3].size())
        {
           ans[++it]=a[3].top() ;  //cout<<a[3].top()<<' ';
            a[3].pop();
        
        }
        if(a[1].size())
        {
             ans[++it]=a[1].top() ;
            a[1].pop();
        
            
        }
    }
     while(a[3].size()>=2&&a[2].size())
     {
        // int f =0 ;
        if(a[3].size())
        {

             ans[++it]=a[3].top() ;
            a[3].pop();
             ans[++it]=a[3].top() ;
            a[3].pop();
        
        }
        if(a[2].size())
        {
            ans[++it]=a[2].top() ;
            a[2].pop();
        
            
        }



        
     }
     while(a[1].size()>=2&&a[2].size())
     {
        // int f =0 ;
        if(a[2].size())
        {
            ans[++it]=a[2].top() ;
            a[2].pop();
            
            
        }
        
        if(a[1].size())
        {
    
             ans[++it]=a[1].top() ;
            a[1].pop();
             ans[++it]=a[1].top() ;
            a[1].pop();
        
        }
        
        
        
    }
    
     while(a[3].size())
     {
       ans[++it]=a[3].top() ;
        a[3].pop();
     }
     while(a[2].size())
     {
       ans[++it]=a[2].top() ;
        a[2].pop();
     }
     while(a[1].size())
     {
       ans[++it]=a[1].top() ;
        a[1].pop();
     }
     while(a[0].size())
     {
        ans[++it]=a[0].top() ;
        a[0].pop();
     }
     int sum =0 ;
     for(int i=1;i<=it;i++)
     {
         sum+=b[ans[i]];
         sum%=4;
         if(sum==1)
         {
            cout<<-1<<'\n';
            return;
         }
     }
     for(int i=1;i<=it;i++)cout<<ans[i]<<' ';
     cout<<'\n';



}

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}