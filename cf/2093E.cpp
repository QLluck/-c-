#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;
int n, k;
int arr[N] = {0};
priority_queue<int> que;
int f(int mid)
{while(!que.empty())
        que.pop();
    int num = 0;
    int mex = 1e9;
    int mext = 0;
    int it = 1;
    while(it<=n)
    {
        que.push(-arr[it]);
        it++;
        while(mext==-que.top())
        {
            mext++;
            que.pop();
            if(mext>=mid)
            {
                num++;
                mex = min(mext, mex);
                mext = 0;
                while(que.size())
                    que.pop();
                break;
                
            }
        }
    }
   // cout << mid << ' ' << num << ' ' << mext << endl;


    if(num>=k)
    {
        return 1;
    }
    else
        return 0;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> arr[i];
    int l = 0 ;
    int r = 2e5 + 1;
    while(l+1!=r)
    {
        int mid = (l + r) >> 1;
        if(f(mid))
            l = mid;
        else
            r = mid;
      //  cout << mid << ' ' << f(mid) << endl;
    }
    
    cout << l << endl;
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();

    }

}