#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
#define ll long long
int me[30] = {0};
int arr[N] = {0};
int sta[30] = {0}, ist;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    string s2;
    cin >> s;
    cin >> s2;
    n = s.size();
    m = s2.size();

    for (int i = 0; i < n; i++)
    {
        if (ist == 0)
            sta[++ist] = i;
        else if (s[sta[ist]] < s[i])
            sta[++ist] = i;
    }
    for (int i = 0; i < m; i++)
    {
        me[(int)(s2[i] - 'a')]++;
    }

    int it1 = 0;
    int it2 = 0;
    for (int i = 1; i <= ist; i++)
    {
        while (it2 < 26 && me[it2] <= 0)
            it2++;

        while (it1 < n && (s[it1] <= s[sta[i]]) && (it2 <= (int)(s[sta[i]] - 'a')))

        {
            while (it2 < 26 && me[it2] <= 0)
                it2++;
            if ((s[it1] - 'a') < it2)
            {
                cout << s[it1];
                it1++;
            }
            else if (it2 < 26 && (me[it2] > 0))
            {
                cout << (char)(it2 + 'a');
                me[it2]--;
            }
            if ((it2 > (int)(s[sta[i]] - 'a')) || (s[it1] > s[sta[i]]))
                break;
        }
        while (it1<n&&  s[it1] <= s[sta[i]] && it2 > (int)(s[sta[i]] - 'a'))
        {
            cout << s[it1];
            it1++;
        }
        while (it2<26&&it2 <= (int)(s[sta[i]] - 'a') && s[it1] > s[sta[i]])
        {
            while (it2 < 26 && me[it2] <= 0)
                it2++;
            if (it2 < 26 && me[it2] > 0)
            {
                me[it2]--;
                cout << (char)(it2 + 'a');
            }
        }
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
    return 0;
}
