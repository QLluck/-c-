#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const int N =2e5+7;
int pix[N]={0};

int arr[N]={0},it;
int arr2[N]={0},it2;


void solve()
{
    int n;
    string s;
    cin>>s;
    int num =0 ;
\
    it=0;
    int nb = 0;
     
  for(int i =0 ;i<s.size() ; i++)
  {
    if(s[i]=='A')num++;
    else if(arr[it]==-1&&num==0)
    {
        arr[it]--;
    }
    else if(arr[it]==-2&&num==0)continue;
    else 

    {   
        if(num==0)
        {
            arr[++it]=-1;
            continue;
        }
        arr[++it]=num;
        arr[++it]=-1;

        
         num =0 ; 

    }
  }
  arr[++it]=num;
//   for(int i =1; i<=it ;i++)cout<<arr[i]<<' ';
//   cout<<'\n'; 
    int ans1 =0 ;
    int flag= 0;
    int mi = 1e9+7;
    for(int i =1; i<=it;i++)
    {
         if(arr[i]>=0)
         { ans1+=arr[i];
            mi = arr[i]?min(arr[i],mi):mi;
         }
         if(arr[i]==-2&&i!=1 )flag=1;
    }
  if(flag)
  {
     cout<<ans1<<'\n';
  }
  else 
  {
      if(arr[it-1]<0&&arr[it]==0)cout<<ans1<<'\n';
      else if(arr[1]<0)cout<<ans1<<'\n';
      else 
      {
           int ans =ans1-mi;
           cout<<ans<<'\n';
      }
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