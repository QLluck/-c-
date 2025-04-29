#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;
int n, k;
int arr[N] = {0};
priority_queue<int> que;
int f(int mid)
<<<<<<< HEAD
<<<<<<< HEAD
{
    while (!que.empty())
        que.pop();

=======
=======
>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
{while(!que.empty())
        que.pop();


<<<<<<< HEAD
>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
=======
>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
    int num = 0;

    int mext = 0;
    int it = 1;
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
=======
>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
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
    if(num>=k)
<<<<<<< HEAD
>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
=======
>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
    {
        return 1;
    }
    else
        return 0;
}
void solve()
{
    cin >> n >> k;
<<<<<<< HEAD
<<<<<<< HEAD
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

=======
=======
>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
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
    
<<<<<<< HEAD
>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
=======
>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
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
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
=======

>>>>>>> f8ce2f35b3b84d5f5eb192e4cc672ac9e4196555
    }

}