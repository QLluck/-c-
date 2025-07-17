#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e3+7;
const int P =998244353;
 int arr[N][N]={0};
int rx[4]={0,1,0,-1};
int ry[4]={1,0,-1,0};
void solve()
{  
     int n;
     cin>>n;
     int it = 0; 
     int f = 0;
     int sum =0 ;
     int num =0 ;
      
     if(n==1)
     {
        cout<<0<<'\n';
        return;
     }
    int x1,y1;

    if(n&1)
    { x1 = n/2+1,y1 = n/2 +1;
         it =3;
      f=0 ;
      sum=1;
      arr[x1][y1]=0;
      x1+=rx[f];
      y1 +=ry[f];
      f=1;
      arr[x1][y1]=sum;
      num=1;

    while(it<=n)
    {
        sum++;
        num++;

        x1+=rx[f];
        y1+=ry[f];
        arr[x1][y1] = sum ;
        //cout<<x1<<' '<<y1<<' '<<f<<' '<<num<<' '<<sum<<'\n';
         if(sum +1 == it*it )
        {
             it+=2;
            sum++;
            x1 +=rx[f];
            y1+=ry[f];
            num=1;

            arr[x1][y1] = sum ;
            f = (f+1)%4 ;

             
        }
    
        else if(num+1==it)
        {
            f = (f+1)%4 ;
            num=0;
        }
    }

    }
    else 
    {  x1 = n/2,y1 = n/2 ;
      it =2;
      f=0 ;
      arr[x1][y1]=0;
    while(it<=n)
    {
        sum++;
        num++;

        x1+=rx[f];
        y1+=ry[f];
        arr[x1][y1] = sum ;
       // cout<<x1<<' '<<y1<<' '<<f<<' '<<num<<' '<<sum<<'\n';
         if(sum +1 == it*it )
        {
             it+=2;
            sum++;
            x1 +=rx[f];
            y1+=ry[f];
            num=1;

            arr[x1][y1] = sum ;
            f = (f+1)%4 ;

             
        }
    
        else if(num+1==it)
        {
            f = (f+1)%4 ;
            num=0;
        }
    }
}
for(int i =1; i<=n;i++)
{
     for(int  j=1;j<=n;j++)cout<<arr[i][j]<<' ';
     cout<<'\n';
}
    
    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}