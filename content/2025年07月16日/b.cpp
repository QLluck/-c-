#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =2e3+7;
const int P =998244353;
 int arr[N]={0};
 ll a,b,c1,c2,c3;
 ll ans =0 ;

 struct node
 {
     ll w,d;
 };
 int me[N]={0};
 queue<node> que;
 void bfs()
 {     node temp1 = {a,0};
       que.push(temp1);
       while(que.size())
       {
         node u = que.front();
         que.pop();
     
         if(u.w==b)
         {
             ans = min(ans,u.d);
             continue;
         }
      for(int i =1; i<=3 ;i++)
      {   int d;
         int w;
         if(i<=2&&u.w>b)continue;
         if(i==1)d=u.d+c1,w=u.w+1; 
         if(i==2)d=u.d+c2,w=u.w-1;
         if(i==3) d=u.d+c3,w=u.w*2;
         if(w<=0||(me[w]<=d&&me[w]!=0))continue;
         me[w]=d;
         node temp2 = {w,d};
         cout<<w<<' '<<d<<'\n';
         que.push(temp2);
      }
        


       }

 }
void solve()
{  
    cin>>a>>b>>c1>>c2>>c3;
    ans =1e18+7;
    for(int i =1; i<N ;i++)me[i]=0;
    bfs();
     
    cout<<ans<<'\n';

    
    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}