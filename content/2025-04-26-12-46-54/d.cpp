#include<bits/stdc++.h>
using namespace std ;
const int N =20+7;
#define ll long long 
char arr[N][N];
int me[N][N]={0};
int X,Y;
int k;
int num=0;

void f(int x,int y)
{   int res =0 ;
    int nl=0;
    int nr=0;
     for(int i =x-1,j=y-1 ; 1<=i&&i<=X && 1<=j&&j<=Y ;i--,j--)
     {
           if(arr[i][j]=='.')break;
           else if(arr[i][j]=='*')
            { if(me[i][j]==0)res++;
                nl++;
            }
     }
     for(int i =x-1,j=y+1 ; 1<=i&&i<=X && 1<=j&&j<=Y ;i--,j++)
     {
           if(arr[i][j]=='.')break;
           else if(arr[i][j]=='*')
            { if(me[i][j]==0)res++;
                nr++;
            }
     }
     int h = min(nr,nl);
     if(h<k)return;
     if(me[x][y]==0)
     {
        res+=1;
        me[x][y]=1;
        num--;
     }
      int it =0;
     for(int i =x-1,j=y-1 ; 1<=i&&i<=X && 1<=j&&j<=Y ;i--,j--)
     {   if(it>h)break;
           if(arr[i][j]=='.')break;
           else if(arr[i][j]=='*')
            {me[i][j]=1;
                num--;
            }
            it++;
     }
     it=0;
     for(int i =x-1,j=y+1 ; 1<=i&&i<=X && 1<=j&&j<=Y ;i--,j++)
     {    if(it>h)break;
           if(arr[i][j]=='.')break;
           else if(arr[i][j]=='*')
            { me[i][j]=1;
                num--;
            }
            it++;
     }
     

}
void solve()
{

   

cin>>X>>Y>>k;
num=0;

for(int i =1; i<=X; i++)
{
     for(int j=1 ;j<=Y ;j++)
     {
          cin>>arr[i][j];
          if(arr[i][j]=='*')num++;
          me[i][j]=0;
     }
}
// for(int i =1; i<=X; i++)
// {
//      for(int j=1 ;j<=Y ;j++)
//      {
//           cout<<arr[i][j];
        
//      }
//      cout<<'\n';
// }
// cout<<num<<'\n';
for(int i =1; i<=X;i++)
{
      for(int j =1;j<=Y;j++)
      {
         if(arr[i][j]=='*')f(i,j);
      }
}
//cout<<num<<'\n';
//cout<<num<<'\n';
if(num==0)cout<<"YES"<<'\n';
else cout<<"NO"<<'\n';


 




    

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}