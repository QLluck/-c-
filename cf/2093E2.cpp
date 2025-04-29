#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;
int n, k;
int arr[N] = {0};

int f(int mid)
{set<int> st;
    int num=0;
   for(int i =1; i<=n;i++)
   {
     if(arr[i]<mid)  st.insert(arr[i]);
     if(st.size()==mid)
     {
         num++;
         st.clear();
     }

   }
   return num>=k;
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