#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;

char a[107][107];
int n;
int debugid = 0;
void debug(int de)
{
    cout << "----------" << (de) << '\n';
}
bool check(int i, int j)
{
    if (1 <= i && i <= n && 1 <= j && j <= n)
        return 1;
    else
        return 0;
}
bool check2(int i, int j)
{
    if (check(i, j) && check(i + 1, j) && check(i, j + 1) && check(i + 1, j + 1))
        return 1;
    else
        return 0;
}
bool check3(int i, int j)
{
    if (a[i][j] == '#' && a[i + 1][j] == '#' && a[i][j + 1] == '#' && a[i + 1][j + 1] == '#')
        return 1;
    else
        return 0;
}
void solve()
{

    cin >> n;
    int z = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '#')
                z++;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << a[i][j];
    //     }
    //     cout << '\n';
    // }
    int flag = 0;
    int flag2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (flag2)
            break;
        for (int j = 1; j <= n; j++)
        {
            if (flag2)
                break;
            if (check2(i, j) && check3(i, j))
            {
                if (z > 4)
                    flag2 = 1;
                else if(z==4)
                    flag2 = 2;
            }
        }
    }
    if (flag2==1)
    {
        cout << "NO" << '\n';
        return;
    }
    else if(flag2==2)
    {
        cout << "YES" << '\n';
        return;
    }
    for (int g = 1; g <= 2 * n - 1; g++)
    {
        if (flag)
            break;
        int i = 1, j = g;
        if (g > n)
            i = g - n + 1, j = 1;

        int n1 = 0;
        int i1 = i, j1 = j;
        // cout << i << ' ' << j << '\n';
        do
        {

            if (check(i1, j1) && a[i1][j1] == '#')
                n1++;
            i1++, j1++;
            // cout << i1 << ' ' << j1 << '\n';
            // debug(check(i1, j1));
        } while (check(i1, j1));

        int n2 = 0;
        i1 = i, j1 = j + 1;

        do
        {
            if (check(i1, j1) && a[i1][j1] == '#')
                n2++;
            i1++, j1++;
        } while (check(i1, j1));
        int n3 = 0;
        i1 = i + 1, j1 = j;
        do
        {
            if (check(i1, j1) && a[i1][j1] == '#')
                n3++;
            i1++, j1++;
        } while (check(i1, j1));
        if (n1 + n2 >= z || n1 + n3 >= z)
            flag = 1;
    }

    for (int g = 1; g <= 2 * n - 1; g++)
    {
        if (flag)
            break;
        int i = 1, j = g;
        if (g > n)
            i = j - n + 1, j = n;

        int n1 = 0;
        int i1 = i, j1 = j;
        do
        {
            if (check(i1, j1) && a[i1][j1] == '#')
                n1++;
            i1++, j1--;
        } while (check(i1, j1));
        int n2 = 0;
        i1 = i, j1 = j - 1;

        do
        {
            if (check(i1, j1) && a[i1][j1] == '#')
                n2++;
            i1++, j1--;
        } while (check(i1, j1));
        int n3 = 0;
        i1 = i + 1, j1 = j;
        do
        {
            if (check(i1, j1) && a[i1][j1] == '#')
                n3++;
            i1++, j1--;
        } while (check(i1, j1));
        if (n1 + n2 >= z || n1 + n3 >= z)
            flag = 1;
    }
    if (flag)
        cout << "YES" << '\n';
    else
        cout << "NO\n";
}
// 0 1 2 3 4 5 6 7
// 0 1 2 3 0 1 2 3

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}