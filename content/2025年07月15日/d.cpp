#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N =1e6+7;
int arr[N]={0};
int t[N]={0};
int b[N]={0};
int q[N][4]={0};
int u[N]={0},it;

int lowbit(int x){return x&-x;}

void add(int x,int k)
{
	while(x<N)
	{
		t[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x )
{
	 int res= 0;
	 while(x)
	 {
		 res+=t[x];
		 x-=lowbit(x);
	 }
	return res;
}
int check(int mid,int fen)
{
	return query(mid)<fen ;
}
void solve(){
	int n,m;
	cin>>n>>m;

	for(int i =1;i <=n;i++)
	{ cin>>arr[i];

             u[++it]=arr[i];
        
		b[i]=arr[i];
	}
	
	for(int i =1;i<=m; i++)
	{
	int x ,d ;
		cin>>x>>d;
        
		 q[i][1]=b[x];
     b[x]+=d;
         q[i][2]=b[x];
             u[++it]=b[x];
	}

    sort(u+1,u+it+1);
    int len = unique(u+1,u+it+1)-u-1;
    for(int i =1;i <=n;i++)
    {   int x = lower_bound(u+1,u+len+1,arr[i])-u;
          add(x,1);
    }
    int l =0 ;
    int sum =n ;
    int fen =n/2;

    while(n-query(l+1)>=fen)
    { 
         l++;
    }

    for(int i =1; i<=m;i++)
    {  //cout<<"--------"<<i<<'\n';
       int x =lower_bound(u+1,u+len+1,q[i][1])-u;
       int y =lower_bound(u+1,u+len+1,q[i][2])-u;
    		add(x,-1);
		add(y,1);
  while(n-query(l+1)>=fen)
    { 
         l++;
    }
     cout<<query(l)<<'\n';
    }

	for(int i=1; i<=n;i++)
    {   int x = lower_bound(u+1,u+len+1,b[i])-u;
        add(x,-1);

    }



	
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
//	T=1;     
	while(T--){
		solve();
	}
}