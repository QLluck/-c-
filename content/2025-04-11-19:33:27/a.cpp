#include<bits/stdc++.h>
using namespace std ;
const int  N = 1e6+7 ;
int arr[N]={0},it1;
int yi[N]={0};
#define ll long long 
void solve()
{
     int  n;
     cin>>n;
     for(int i =1; i<=n ;i++)
      { cin>>arr[i];
        if(i==1)yi[i]=arr[i];
        else yi[i]=yi[i-1]^arr[i];
      }
     for(int i  =1; i<=100 ;i++)
    {
        if(i<=n)cout<<arr[i]<<' ';
    else 
    {   arr[i]=yi[i/2];

        yi[i]=arr[i]^yi[i-1];
        cout<<arr[i]<<' ';

    }
   
    }
    cout<<'\n';
    for(int i =1; i<=10; i++)
    {
         cout<<yi[i]<<' ';
    }
    cout<<'\n';
   
    
      
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     int t;
     cin>>t ;
     while(t--)
     solve();
}