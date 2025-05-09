#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int it,num ;
};
bool cnt(node a,node b){return a.num<b.num;}
node arr[4];
void solve()
{ arr[1].it=1;
    arr[2].it=2;
    arr[3].it=3;
    arr[1].num=0;
    arr[2].num=0;
    arr[3].num=0;
    map<int,int>mp;
    string s ;
    int n;
    cin>>n;
    cin>>s;
    for(int i =0; i<n;i++)
    {
        if(s[i]=='L')
         { arr[1].num++;
              if(i<n-1&&s[i+1]=='I')mp[3]++;
              else if(i<n-1&&s[i+1]=='T')mp[2]++;
              
         }
        else if(s[i]=='I')
        { arr[2].num++;
            if(i<n-1&&s[i+1]=='L')mp[3]++;
              else if(i<n-1&&s[i+1]=='T')mp[1]++;
        }
        else if(s[i]=='T')
        { arr[3].num++;
            if(i<n-1&&s[i+1]=='L')mp[2]++;
              else if(i<n-1&&s[i+1]=='I')mp[1]++;
        }
    }
    sort(arr+1,arr+4,cnt);
    int a1 = arr[1].num + mp[arr[1].it];
    int ans =0 ;
    if(a1>=arr[2].num)
    {
      ans+= arr[2].num-arr[1].num;
      ans+= 2*(arr[3].num-arr[2].num);
      
    }
    else 
    {
        
    }


}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
       
}