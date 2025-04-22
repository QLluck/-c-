#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
double sovle(double a,double b,double n)
{
    double sum=0;
    double y=0;
    for(double i = 0.00001; i <a; i += 0.00001)
    {
        y=b*pow(1-pow((double)i/a,n),(double)1/n);
        sum+=0.00001*y;
    }
                   return sum*4;
}
signed main()
{
    double a,b,n;
    cin>>a>>b>>n;
    double sum=sovle(a,b,n);
    printf("%.6lf\n",sum);
    return 0;
}