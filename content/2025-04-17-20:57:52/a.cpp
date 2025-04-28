#include<bits/stdc++.h>
using namespace std ;
const int N =1e4+7;
#define ll long long 
char arr[57][57]={0};
int X,Y;
int a[57]={0};
int b[57]={0};
int f(int i ,int j )
{
      
      if(arr[i-1][j]=='1'||arr[i][j-1]=='1')return 1 ;
      else return 0 ;
}

void solve()
{
     
    cin>>X>>Y;
   map<int,int> a[X];
   map<int,int> b[Y];
   for(int i =0; i<X; i++)
   for(int j =0;j<Y ;j++)
     {  cin>>arr[i][j];

     }
   for(int i =0 ; i<X;i++)
   {
     for(int j = 0 ; j<Y ;j++)
     {
         if(arr[i][j]=='0')break;
         else a[i][j]=1;
     }
   }
   for(int i =0 ; i<Y;i++)
   {
     for(int j = 0 ; j<X ;j++)
     {
         if(arr[j][i]=='0')break;
         else b[i][j]=1;
     }
   }
   for(int i =0 ; i<X;i++)
   {
     for(int j = 0 ; j<Y ;j++)
     {
        if(arr[i][j]=='1')
        {
             if(a[i].count(j)|| b[j].count(i) )continue;
             else 
             { cout<<"NO"<<'\n';
                return; 
             }
        }
     }
   }
   
   cout<<"YES"<<'\n';


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}