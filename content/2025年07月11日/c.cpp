#include<bits/stdc++.h>
using namespace std;
const int  N = 1e5+7;
const int INF =1e9+7;
int a[N]={0};
int b[N]={0};
int as[N]={0},it1;
int bs[N]={0},it2;
int ans[N],it;
#define ll long long

void solve()
{
    int n,k;
    cin>>n>>k;
    it=0;
    it1=0;
    it2=0;
map<int,int>mpa;

for(int i =1; i<=n;i++)
{ cin>>a[i];
    mpa[a[i]]++;
    if(mpa[a[i]]==2)
    { as[++it1]=a[i];
        as[++it1]=a[i];
        
    }
  
}
//cout<<it1<<'\n';

map<int,int> mpb;
for(int i =1; i<=n;i++)
{cin>>b[i];
    mpb[b[i]]++;
    if(mpa[b[i]])ans[++it]=b[i];
    if(mpb[b[i]]==2)
    { bs[++it2]=b[i];
        bs[++it2]=b[i];
    }


    
}

int ita =1 ;
int itb = 1;
int len = 2*k ;
it =1;

  while(ita<=len&&ita<=it1)
  {
      cout<<as[it]<<' ';
      it++;
      ita++;
  }
  it =1;
for(; ita<=len ;ita++)
{
     cout<<ans[it]<<' ';
     it++;
}
cout<<'\n';
it =1 ;
  while(itb<=len&&itb<=it2)
  {
      cout<<bs[it]<<' ';
      it++;
      itb++;
  }
  it =1;
  for(; itb<=len ;itb++)
{
     cout<<ans[it]<<' ';
     it++;
}

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