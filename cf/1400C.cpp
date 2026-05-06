/* ========================================= */
/* 题目名称：1400C */
/* 创建时间：2026-02-03 22:04:27 */
/* 完成时间：*/
/* 备注：无 */
/* ========================================= */
/* 完成时间：2026-02-03 23:27:06 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int ans[N];
void solve(){
    //111010111
    //01110
    //010
    //0110
    //01110
    //111110001
    //111100000100
    int x;
    string s;

    cin>>s;
    s=" "+s;
        int n= s.size();
        n--;
    cin>>x;
    // for(int i=1;i<=x;i++)
    // {
    //     int it =i;
    //     while(it<=n)cout<<s[it],it+=x;
    //     cout<<'\n';
    // }
    for(int i=1;i<=n;i++)ans[i]=0;
    for(int i=1;i<=n;i++)
    {
        // int it = i;
        // int flag =0;
        // while(it<=n)
        // {
        //     flag=0;
        //     if(it-2*x >=1  &&s[it]=='1'&& s[it-2*x]=='1')flag=1;
        //     if(it+2*x <=n  &&s[it]=='1'&&s[it+2*x]=='1')flag=1;
        //     if(it-2*x<1 && it+2*x>n &&s[it]=='1')flag=1;
        //     if(s[it]=='0')
        //     { 
        //         flag=1;
        //     if(it-x >=1)ans[it-x]=1;
        //     if(it+x <=n)ans[it+x]=1;
        //     }
        //     it+=x;
        // if(flag==0)
        // { 
        //     // cout<<i<<' '<<it<<'\n';
        //     cout<<-1<<'\n';
        //     return;
        // }
        // }
        if(s[i]=='0')
        { 
         if(i-x >=1)ans[i-x]=1;
         if(i+x <=n)ans[i+x]=1;
        }
    }
    int flag= 0 ;
    for(int i=1;i<=n;i++)
    {
        flag=0;
        if(s[i]=='0')continue;
        else 
        {
        if(i-x >=1&&ans[i-x]==0)flag=1;
         if(i+x <=n&&ans[i+x]==0)flag=1;
        //  if(i-x<1 && i+x>n )flag=1;
        }
    if(flag==0)
    { 
    // cout<<i<<' '<<it<<'\n';
    cout<<-1<<'\n';
    return;
    }

    }
    for(int i=1;i<=n;i++)cout<<(ans[i]?0:1);
    cout<<'\n';

}

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}