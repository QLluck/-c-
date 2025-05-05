#include<bits/stdc++.h>
using namespace std ;
const int N =400;
int t[N][N]={0};
int arr[N][N]={0};
int me[N][N]={0};

struct node2
{
     int x,y,it;
     
};
struct node
{
     int x ,y,step,it;
     node2 r[5];

};
node2 r[10];
int bx,by;


int n;
queue<node> que; 
void bfs( )
{
     node temp1;
     temp1.x=1;
     temp1.y=1;
     temp1.step=1;
     temp1.it=4;
     temp1.r[1]=r[1];
     temp1.r[2]=r[2];
     temp1.r[3]=r[3];

     me[1][1]=1;
     
     que.push(temp1);
     while(que.size())
     {
        node u=que.front();
        que.pop();

            for(int i =1; i<=3;i++)
            {
                int x1 =u.x+u.r[i].x;
                int y1 =u.y+u.r[i].y;
                int it=u.r[i].it;
                int step=u.step+1;
                 if(x1<=0||x1>n||y1<=0||it!=arr[x1][y1]||y1>2*(x1-1)+1||(me[x1][y1]!=0&&step>=me[x1][y1] ))continue;
              
                 me[x1][y1]=step;
                 node temp;
                 if(i==1)
                 {
                   
                    temp.x=x1;
                    temp.y=y1;
                    temp.it=u.r[i].it;
                    temp.step=step;
                    temp.r[1]=u.r[1];
                    temp.r[1].it=u.r[3].it;

                    temp.r[2]=u.r[2];
                    temp.r[2].it=u.it;

                    temp.r[3]=u.r[3];
                    temp.r[3].it=u.r[2].it;
                    if(step&1)
                    {
                        temp.r[3].x=1;
                        temp.r[3].y=1;
                    }
                    else 
                    {
                        temp.r[3].x=-1;
                        temp.r[3].y=-1;
                    }
                }
                else  if(i==2)
                 {
                  
                    temp.x=x1;
                    temp.y=y1;
                    temp.it=u.r[i].it;
                    temp.step=step;
                    temp.r[1]=u.r[1];
                    temp.r[1].it=u.it;

                    temp.r[2]=u.r[2];
                    temp.r[2].it=u.r[3].it;

                    temp.r[3]=u.r[3];
                    temp.r[3].it=u.r[1].it;
                    if(step&1)
                    {
                        temp.r[3].x=1;
                        temp.r[3].y=1;
                    }
                    else 
                    {
                        temp.r[3].x=-1;
                        temp.r[3].y=-1;
                    }

                 }
                else  if(i==3)
                 {
                   
                    temp.x=x1;
                    temp.y=y1;
                    temp.it=u.r[i].it;
                    temp.step=step;
                    temp.r[1]=u.r[1];
                    temp.r[1].it=u.r[1].it;

                    temp.r[2]=u.r[2];
                    temp.r[2].it=u.r[2].it;

                    temp.r[3]=u.r[3];
                    temp.r[3].it=u.it;
                    if(step&1)
                    {
                        temp.r[3].x=1;
                        temp.r[3].y=1;
                    }
                    else 
                    {
                        temp.r[3].x=-1;
                        temp.r[3].y=-1;
                    }
             
                 }
                
              que.push(temp);
               
            }
        
       

     }
    
}
void solve()
{
  
  cin>>n;
  for(int i =1; i<=n;i++)
  {
     for(int j=1; j<=2*(i-1)+1;j++)
     {
         cin>>arr[i][j];
     }
  }
  cin>>bx>>by;
  //cout<<"YES"<<'\n';
  bfs();
  int ans = me[bx][by];
  if(ans)
  {
    cout<<ans-1<<'\n';
  }
  else cout<<-1<<'\n';


    
}

int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    node2 t1 ={0,-1,1};
    node2 t2={0,1,3};
    node2 t3={1,1,2};
    r[1]=t1;
    r[2]=t2;
    r[3]=t3;

    solve();
}