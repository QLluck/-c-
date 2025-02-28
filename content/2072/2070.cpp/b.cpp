// 顺序表
#include <bits/stdc++.h>
using namespace std; 
const int N = 2e5+7  ;
#define ll long long 
int arr[N]={0};
void solve()
{
    ll n,x,k;
    cin>>n >>x>>k;
    string s ;
    cin>>s ;
    arr[0]=1 ;
   int  flag = 0 ; 
      int it1 =-1  ; 
      int it2 = -1 ; 
      map<int ,int > mp;
    for(int i = 0 ; i <n ;i++)
    {
          if(s[i]=='R')arr[i]=arr[i-1]+1 ;
          else arr[i]=arr[i-1]-1 ;
          if(arr[i]==0) flag ++ ;
          if(flag ==1 ) it1 = i ;
          if(mp.count(arr[i]))
          {
              it2 = arr[i];
              if(it1!=-1&& )
          }
          
    }
    if(flag ==2 )
    {
          
    }
   
       
   
}

int main()
{

    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}