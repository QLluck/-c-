#include<bits/stdc++.h>

using namespace std; 

int main()
{
     string s;
     s = "heell lll lll ss aa  ba d dasd ";
     regex pattern("l{3}");
     smatch  arr ;
     while(regex_search(s,arr,pattern))
     {
          cout << arr[0] << '\n';
          s = arr.suffix().str();
     }
}