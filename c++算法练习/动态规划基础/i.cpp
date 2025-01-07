#include<bits/stdc++.h>
int main()
{
      int arr[2][4]={0,1,2,3,4,5,6,0};
      for(int i= 0 ; i < 2 ;i++)
      {
        for(int j = 0 ; j< 4; j++)
        {
              printf("%zu ", (size_t)(&arr[i][j]));
        }
        printf("\n") ;
      }

}