#include <bits/stdc++.h>
using namespace std;
const int N = 5007;
int arr[N] = {0};
int prime[N]={0},it;
int me[N]={0};
void pri()
{
    me[0]=1;
    me[1]=1;
    for(int i=2; i<N ;i++)
    {
         if(!me[i])prime[it++]=i;
         for(int j= 0 ;j<it ;j++)
         {
             if(i*prime[j]>=N)break;
             me[i*prime[j]]=1;
             if(i%prime[j]==0)break;
         }
    }
}
void solve()
{
   
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    pri();
    cout<<it<<'\n';
    
    //printb(2);
}