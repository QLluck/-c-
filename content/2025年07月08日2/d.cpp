#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int N =1e5+7;

int arr[N]={0};
void solve()
{
    

  int n,x,y;
  cin>>n>>x>>y;

  int it= 0 ;
  for(int i =y ; i<=x ;i++)arr[i]=1;
  for(int i = y-1 ;i>=1 ;i--)
  {
     if(it&1) arr[i]=1;
     else arr[i]=-1;
     it++;
  }
  it =0 ;
  for(int i = x+1 ;i<=n ;i++)
  {
    if(it&1) arr[i]=1;
     else arr[i]=-1;
     it++;
  }
  
for(int i =1; i<=n;i++)cout<<arr[i]<<' ';
cout<<'\n';


}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}