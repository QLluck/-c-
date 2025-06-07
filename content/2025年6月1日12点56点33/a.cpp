#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 7;
map<char, char> mp;
typedef struct Lnode
{
    Lnode *next;
    Lnode *re;
    char data;
} LN;
typedef struct Llist
{
    LN *head;
    LN *tail;
    Llist *next;
    Llist *re;
} L;
void print(L *head)
{
    for (L *p1 = head; p1 != NULL; p1 = p1->next)
    {
        for (LN *p2 = p1->head->next; p2 != NULL; p2 = p2->next)
        {
            cout << p2->data;
        }
        cout << '\n';
    }
}

int it;
L* init()
{
    L *p = new L;
    p->next = NULL;
    p->re = NULL;
    LN *h = new LN;
    h->next = NULL;
    h->re = NULL;

    p->head = h;
    p->tail = h;
    return p;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int shift = 0; 
    
    it =0 ;
    it++;
    L *head = init();
    L *han = head;
    L *tail = head;
    LN *p = head->head;
    int hann = 1;
    int i = 0;
    while(i<n)
    {
         if(i+4<n &&s.substr(i,5)=="SHIFT") 
         {
             shift = !shift;
             i += 5;
         }
         else if (i+4<n&&s.substr(i, 5) == "ENTER")
         {
             
            if(han->next==NULL)
            {
                L *temp = init();
                tail->next = temp;
                temp->re = tail;
                tail = temp;
               
            }
            else
            {
                L *temp = han->next;
                L *temp2 = init();
                han->next = temp2;
                temp2->re = han;
                temp2->next = temp;
                temp->re = temp2;
            }
            
            LN *th1 = p->next;
            p->next = NULL;
           if(th1!=NULL) han->next->tail = han->tail;
            han->tail = p;
            LN *th2 = han->next->head;
            th2->next = th1;
          if(th1!=NULL)  th1->re = th2;
          han = han->next;
          p = han->head;
          i += 5;
         }
         else if (i+8<n&&s.substr(i, 9) == "BACKSPACE")
         {
            if(p==han->head)
            {
                if(han!=head)
                {
                    L* han1 = han->re;
                    L *han2 = han->next;
                    LN *th1 = p->next;
                    LN *th2 = han1->tail;
                    th2->next = th1;
                   if(th1!=NULL) th1->re = th2;
                    if(th1!=NULL)han1->tail = han->tail;
                    han1->next = han2;
                    if(han2!=NULL)
                        han2->re = han1;
                    han = han1;
                    p = th2;
                }
               
            }
            else 
            {
                LN *th1 = p->re;
                LN *th2 = p->next;
                th1 ->next = th2;
               if(th2!=NULL) th2->re = th1;
               if(p==han->tail)
                   han->tail = th1;
                p= th1;  
            }

            i += 9;
         }
         else if (i+2<n&&s.substr(i, 3) == "DEL")
         {
            if(p->next==NULL)
            {
                if(han->next!=NULL)
                {
                    han = han->next;
                    p = han->head;
                    //搬
                    L *han1 = han->re;
                    L *han2 = han->next;
                    LN *th1 = p->next;
                    LN *th2 = han1->tail;
                    th2->next = th1;
                    if (th1 != NULL)
                        th1->re = th2;
                    if (han->tail != han->head)
                        han1->tail = han->tail;
                    han1->next = han2;
                    if (han2 != NULL)
                        han2->re = han1;
                    han = han1;
                    p = th2;
                }
            }
            else 
            {
                p = p->next;
                LN *th1 = p->re;
                LN *th2 = p->next;
                th1->next = th2;
                if (th2 != NULL)
                    th2->re = th1;
                if (p == han->tail)
                    han->tail = th1;
                p = th1;
            }
            i += 3;
         }
         else if (i+3<n&&s.substr(i, 4) == "LEFT")
         {
            if(p==han->head)
            {
                if(han!=head)
               {
                   han = han->re;
                   p = han->tail;
               }
            }
            else
            {
                p = p->re;
            }
            i += 4;
         }
         else if (i+4<n&&s.substr(i, 5) == "RIGHT")
         {
            if(p->next==NULL)
            {
                 if(han->next!=NULL)
                 {
                     han = han->next;
                     p = han->head;
                 }
            }
            else
            {
                p = p->next;
            }
             i += 5;
         }
         else if (i+1<n&&s.substr(i, 2) == "UP")
         {
           if(han!=head)
           {
               LN *p1 = han->re->head;
               while (p1->next != NULL && p != han->head )
               {
                   p1 = p1->next;

               }
               p = p1;
               han = han->re;
           }
           i += 2;
         }
         else if (i+3<n&&s.substr(i, 4) == "DOWN")
         {
             if (han ->next!=NULL)
             {
                 LN *p1 = han->next->head;
                 while (p1->next != NULL && p != han->head)
                 {
                     p1 = p1->next;
                 }
                 p = p1;
                 han = han->next;
             }
             i += 4;

         }
         else if (i+3<n&&s.substr(i, 4) == "HOME")
         {
             p = han->head;
             i += 4;
         }
         else if (i+2<n&&s.substr(i, 3) == "END")
         {
             p = han->tail;
             i += 3;
         }
         else
         {
             char data;
             if ('a' <= s[i] && s[i] <= 'z')
             {
                 if(shift)
                 {
                     data = (char)(s[i] - 32);
                 }
                 else
                 {
                     data = s[i];
                 }

            }
            if('0'<=s[i]&&s[i]<='9')
            {  if(shift)
                data = mp[s[i]];
                else
                    data = s[i];
            }

            LN *p2 = p->next;
            LN *temp = new LN;
            temp->data = data;
            p->next = temp;
            temp->re = p;
            temp->next = p2;
            if (p2 == NULL)
            {
                han->tail = temp;
                p = temp;
            }
            else
            {
                p2->re = temp;
            }
            i += 1;
         }
        // print(head);
        // print(head);
        //  cout<<"---------------"<<'\n';
    }
    print(head);
    
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
   
    mp['1'] = '!';
    mp['2'] = '@';
    mp['3'] = '#';
    mp['4'] = '$';
    mp['5'] = '%';
    mp['6'] = '^';
    mp['7'] = '&';
    mp['8'] = '*';
    mp['9'] = '(';
    mp['0'] = ')';
    solve();
}