#include<iostream>
#include<algorithm>
using namespace std ;
const int N = 1e2+7 ;
const int inf = 1e9+7;
int d[N][N]={0},e[N][N]={0};
int n,m;
void flo()
{
    for(int k=0;k<n;k++)
        for(int i = 0 ; i <n ;i++)
            for(int j =0 ; j<n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
void solve()
{

   
        for(int i= 0 ;i<n ;i++)
        for(int j =0 ;j<n ;j++)
           if(i!=j) d[i][j]=inf;
        for(int i =1 ;i<=m ;i++)
        {
             int a,b;
             cin>>a>>b;
             d[a][b]=1;
             d[b][a]=1;
            
        }
        flo();
        for(int i =0 ; i<n ;i++)
            for(int j =0 ; j<n ;j++)
                if(d[i][j]>7)
                {
                    cout<<"No"<<'\n';
                    return  ;
                }
        cout<<"Yes"<<'\n';
        
    
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     while(cin>>n>>m)
     solve();
}