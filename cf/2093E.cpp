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

    int mext = 0;
    int it = 1;

    // cout<<mid<<'\n';
    // cout<<"----------------"<<'\n';
    while (it <= n)
    {
        que.push(-arr[it]);
        it++;
        while (!que.empty() && mext > -que.top())
            que.pop();
        while (!que.empty() && mext == -que.top())
        {
            mext++;
            while (!que.empty() && mext > -que.top())
                que.pop();

            if (mext >= mid)
            {
                num++;

                mext = 0;
                while (que.size())
                    que.pop();
                //  cout<<"yes"<<'\n';
                break;
                
            }
            // cout<<it<<' '<<mext<<'\n';
        }
    }
    if (num >= k)

    //cout<<mid<<'\n';
   // cout<<"----------------"<<'\n';
    while(it<=n)
    {
        que.push(-arr[it]);
      //  cout<<arr[it]<<' '<<'\n';
        it++;
        while(!que.empty()&&mext>-que.top())que.pop();
        while(!que.empty()&&mext==-que.top())
        {
            mext++;
            while(!que.empty()&&mext>-que.top())que.pop();

            if(mext>=mid)
            {
                num++;
               
                mext = 0;
                while(que.size())
                    que.pop();
                  //  cout<<"yes"<<'\n';
                break;
                
                
            }
            //cout<<it<<' '<<mext<<'\n';
            
        }
    }
  return 1;
}
void solve()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int l = 0;
    int r = 2e5 + 1;
    while (l + 1 != r)
    {
        int mid = (l + r) >> 1;
        if (f(mid))
            l = mid;
        else
            r = mid;
        //  cout<<l <<' '<<r <<' '<<mid<<' '<<f(mid)<<'\n';
    }


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
      //  cout<<l <<' '<<r <<' '<<mid<<' '<<f(mid)<<'\n';
    }
    

    cout << l << '\n';
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