#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,M=998244353;
int d[N],f[N];
int n,m;

struct node{
    int v; 
    int w;  
};


struct node1{
    int v;  
    int w;  
    bool friend operator < (const node1& a, const node1& b){
        return a.w > b.w;  
    }
};

vector<char>a[N];     
vector<node>e[N];      

int dijkstra()
{
    memset(d, 0x3f, sizeof(d));  
    memset(f, -1, sizeof(f));    
    priority_queue<node1>q;    
    
    d[1] = 0;                  
    q.push({1, 0});
    
    while(!q.empty()){
        auto top = q.top();
        q.pop();
        int v = top.v;
        int current_w = top.w;  
        
        if(f[v] != -1) continue;  
        f[v] = 1;                 
        
        for(int i = 0; i < e[v].size(); i++){
            int j = e[v][i].v;  
            int weight = e[v][i].w;  
            
            if(d[j] > d[v] + weight){
                d[j] = d[v] + weight;
                q.push({j, d[j]});
            }
        }
    }
    return d[n * m]; 
}

void solve()
{
    int k;
    cin >> n >> m >> k;
    

    for(int i = 1; i <= n; i++){
        a[i].resize(m + 1);
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int u = (i - 1) * m + j; 
            
            if(a[i][j] == 'U'){
                if(i > 1){
                    int v = (i - 2) * m + j;
                    e[u].emplace_back(v, 0);
                }

                if(j < m){
                    int v = (i - 1) * m + j + 1;
                    e[u].emplace_back(v, 1);
                }
                if(j > 1){
                    int v = (i - 1) * m + j - 1;
                    e[u].emplace_back(v, 1);
                }
                if(i < n){
                    int v = i * m + j;
                    e[u].emplace_back(v, 1);
                }
            }
            else if(a[i][j] == 'D'){
                if(i > 1){
                    int v = (i - 2) * m + j;
                    e[u].emplace_back(v, 1);
                }
                if(j < m){
                    int v = (i - 1) * m + j + 1;
                    e[u].emplace_back(v, 1);
                }
                if(j > 1){
                    int v = (i - 1) * m + j - 1;
                    e[u].emplace_back(v, 1);
                }
                if(i < n){
                    int v = i * m + j;
                    e[u].emplace_back(v, 0);
                }
            }
            else if(a[i][j] == 'L'){
                if(i > 1){
                    int v = (i - 2) * m + j;
                    e[u].emplace_back(v, 1);
                }
                if(j < m){
                    int v = (i - 1) * m + j + 1;
                    e[u].emplace_back(v, 1);
                }
                if(j > 1){
                    int v = (i - 1) * m + j - 1;
                    e[u].emplace_back(v, 0);

                }
                if(i < n){
                    int v = i * m + j;
                    e[u].emplace_back(v, 1);
                }
            }
            else if(a[i][j] == 'R'){
                if(i > 1){
                    int v = (i - 2) * m + j;
                    e[u].emplace_back(v, 1);
                }
                if(j < m){
                    int v = (i - 1) * m + j + 1;
                    e[u].emplace_back(v, 0);
                }
                if(j > 1){
                    int v = (i - 1) * m + j - 1;
                    e[u].emplace_back(v, 1);
                }
                if(i < n){
                    int v = i * m + j;
                    e[u].emplace_back(v, 1);
                }
            }
        }
    }
    
    int ans = dijkstra();
    if(ans <= k){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    for(int i = 1; i <= n * m; i++){
        a[i].clear();
        e[i].clear();
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}