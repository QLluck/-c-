#include<iostream>
#include<algorithm>
using namespace std ;
const int N = 2e5+7;
struct node
{
      char x,y;
      int w ;
}arr[N];
int me[30]={0} ;
bool f(node a,node b)
{
     return a.w<b.w;
}
int find(int x )
{ 
     if(me[x]==x)return x ;
     else return me[x]=find(me[x]);
}
int zt(int it)
{   int ans= 0 ; 
     for (int i =1 ; i<=it ;i++)
     {
          if( find(arr[i].x)!= find(arr[i].y) )
          {
             ans+= arr[i].w;
             me[ find(arr[i].x)] = find(arr[i].y) ;
          }
          else 
          {
             continue ;
          }
     }
     return ans; 
}
void solve()
{   int a ;
    while(cin>>a)
    {     
        
         if(a==0)return ;
         
         for(int i =0; i<=a; i++)me[i]=i;
        int it = 0 ; 
         for(int i  = 1 ; i<a ;i++)
         {
             char c ;
             int n ;
             cin>>c>>n;
             for (int j =1 ; j<=n ;j++)
             {     char d ;
                   int  w;
                   cin>>d>>w;
                   arr[++it].x=c-'A' ;
                   arr[it].y =d-'A' ;
                   arr[it].w=w ;
             }
         }
         sort(arr+1,arr+1+it,f);
        //  for (int i =1 ;i<=it ;i++)
        //  {
        //      cout<<arr[i].x<<' '<<arr[i].y<<' '<<arr
        //  }
         cout<<zt(it)<<'\n';
         
    }
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}