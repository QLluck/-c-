#include<bits/stdc++.h>
using namespace std ;
<<<<<<< HEAD
int n,k;
const int N = 2e5 + 7;
int arr[N] = {0};
int pix[N] = {0};
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
    {
        cin >> arr[i];
        pix[i] = arr[i] ^ pix[i - 1];
    }
     
} 
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        
    solve();
=======
const int N =1e5+7;
int cnt[N]={0};
int t[N*32][2]={0},it;
int arr[N]={0};
void add(int x )
 {     //cout<<"-------------"<<'\n';
//      cout<<x<<'\n';
     for(int j = 30,i=0 ;j >=0 ;j-- )
     {   int wei = x>>j&1;
       // cout<<wei;

          if(wei)
          {
              if(t[i][1]==0)
              {
                  t[i][1]=++it;
                  t[it][1]=0;
                  t[it][0]=0;
                  cnt[it]=0;
                  cnt[it]++;
                  i=it;
               // cout<<x<<'\n';
              }
              else 
              {
               i= t[i][1];
               cnt[i]++;
              }
          }
          else 
          { //cout<<i<<' '<<t[i][1]<<' '<<t[i][0]<<'\n';
            if(t[i][0]==0)
            {
                t[i][0]=++it;
                //cout<<it<<' '<<t[i][0]<<'\n';
                t[it][1]=0;
                t[it][0]=0;
                cnt[it]=0;
                cnt[it]++;
                i=it;
               // cout<<x<<'\n';
            }
            else 
            {
             i= t[i][0];
             cnt[i]++;
            }
          }
         // x>>=1;
     }
   //  cout<<'\n';
}
void delte(int x )
{
    int i= 0;
    for(int j = 30,i=0 ;j >=0 ;j-- )
     {
        int wei = x>>j&1;
          if(wei)
          {
             
              
               i= t[i][1];
               cnt[i]--;
              
          }
          else 
          {
            
           
             i= t[i][0];
             cnt[i]--;
            
          }
         // x>>=1;
     }
}
int query(int x )
{  int res= 0 ;
    int sum = 1<<30;
    int i = 0 ;
   // cout<<x<<'\n';
    for(int j = 30,i=0 ;j >=0 ;j-- )
    {
        int wei = x>>j&1;
       //cout<<wei<<' '<<t[i][0]<<' '<<t[i][1]<<' '<<cnt[t[i][0]]<<' '<<cnt[t[i][1]]<<' '<<sum<<'\n';
         if(wei)
         {
            
             
             if(cnt[t[i][0]]&&t[i][0])
              { 
                
                i= t[i][0];
                res+=sum;
             //  cout<<"YES"<<' '<<res<<' '<<sum<<'\n';
                
              }
             else i=t[i][1];
              
             
         }
         else 
         {
           
          
          if(cnt[t[i][1]]&&t[i][1]) 
          { 
            i= t[i][1];
            res+=sum;
          //  cout<<"YES"<<' '<<res<<' '<<sum<<'\n';
            //cnt[i]--;
          }
          else 
           { i=t[i][0];
           }
           
         }
        // x>>=1;
         sum>>=1;
       // cout<<j<<' '<<res<<'\n';
    }
    return res;
}
void solve()
{
   int n,k;
   cin>>n>>k;
   it =0 ; 
   t[0][0]=0;
   t[0][1]=0;
   for(int i =1; i<=n;i++)cin>>arr[i];
   int l =1;
   int r =1; 
   int ans = n+1;
   int ma = 0 ;


   while(r<=n)
   {//cout<<arr[r]<<'\n';
     add(arr[r]);
     ma = query(arr[r]);
    // cout<<ma<<' '<<l <<' '<<r<<'\n';
     while(l<=r&&ma>=k)
     {ans=min(r-l+1,ans);
         delte(arr[l]);
         l++;
         ma = query(arr[r]);
        
     }
     if(ans==1)
     {
        cout<<1<<'\n';
        return;
     }
     r++;
   }
   if(ans==n+1)cout<<-1<<'\n';
   else cout<<ans<<'\n';
}
void dfs(int i)
{    
    if(cnt[i]==0)return;
    if(t[i][1])
     {  cout<<1<<'\n';
        dfs(t[i][1]);
     }
    if(t[i][0])
    { cout<<0<<'\n';
        dfs(t[i][0]);
    }
    
      
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    cnt[0]++;
    int t;
    cin>>t;
    while(t--)
    solve();
    
    //  for(int i =1; i<=5 ;i++)
    //  {
    //    add(i);
    //    cout<<query(i)<<'\n';
    //  }
     //cout<<it<<'\n';
    // add(1);
    // add(10);
    // cout<<query(1);
    //dfs(0);
   
    
>>>>>>> d99a870b89e73c90663814572f67bd5c1e5ddbca
}