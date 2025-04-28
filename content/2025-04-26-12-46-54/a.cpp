#include<bits/stdc++.h>
using namespace std ;
const int N =57 ;
int arr[N]={0};
pair<int,int> b[N];


void solve()
{
   int n;
   cin>>n;
   for(int i =1; i<=n;i++)
    { cin>>arr[i];
        b[i].first=arr[i];
        b[i].second=i;
    }
    sort (b+1,b+1+n);
    int it = 1;
    int it2=1;
    int r =0 ;
while(it2<=n)
{
    cout<<b[it].first<<' ';
    if(it2==b[it].second)
    {
       
        it++;
        it2++;
        continue;
    }
    while(it2<b[it].second)
    {
       cout<<arr[it2]<<' ';
       it2++;

    }
    if(it2==n)break;
    while(it<n&&b[it].second<it2)it++;
    it2++;
   
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