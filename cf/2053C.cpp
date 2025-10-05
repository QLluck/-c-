#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 3e5+7;
const int mod = 998244353;
int a[N];
int lowbit(int x){return x&-x;}
void solve()
{

   
}
void test()
{
    int n,k;
    cin>>n>>k;
    queue<pii> que;
    que.push({1,n});
    int sum =1;
    int num = 0 ;
    int n1 = n;
    int it = 0;
    while(n1)
    {
        num++;
        n1/=2;
    }
    num--;
    while(que.size())
    {
        int l =que.front().fi ;
        int r = que.front().se;
        
        que.pop();
        sum++;
        cout<<l<<' '<<r<<' ';
        // if(lowbit(sum)==sum)cout<<'\n';12 0
        if(lowbit(sum)==sum)
        {     cout<<((n>>(num-it)) &1);
            it++;

            cout<<'\n';
        }
        int len = r-l+1 ;
        int m =(l+r)/2;
        if(l==r)continue;
        if(len<k)continue;
        if(len&1)
        {
            // cout<<m<<' ';
            que.push({l,m-1});
            que.push({m+1,r});
        }
        else 
        {
            // cout<<m<<' ';
            que.push({l,m});
            que.push({m+1,r});
        }

    }
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    // { solve();
    // }
    // te();
    test();
}
