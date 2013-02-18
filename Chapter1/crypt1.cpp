/*
ID: a.sanya1
LANG: C++
TASK: crypt1
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fi("crypt1.in");
ofstream fo("crypt1.out");
 
int n;
bool num[10];
 
bool iscow( int t )
{
     int extra;
     while( t!=0 ){
            extra=t%10;
            if( !num[extra] )
                return false;
            t/=10;
     }
     return true;
}
 
void input()
{
     for( int i=0;i<=9;i++ )
          num[i]=false;
     fi>>n;
     int t;
     for( int i=1;i<=n;i++ ){
          fi>>t;
          num[t]=true;
     }
}
 
void solve()
{
     int t1,t2,ans,count=0;
     for( int i=100;i<999;i++ ){
          if( !iscow(i) )
              continue;
          for( int j=10;j<99;j++ ){
               if( !iscow(j) )
                   continue;
 
               t1=i*(j%10);
               if( t1>999 )
                   continue;
               if( !iscow(t1) )
                   continue;
 
               t2=i*(j/10);
               if( t2>999 )
                   continue;
               if( !iscow(t2) )
                   continue;
 
               ans=t1+t2*10;
 
               if( ans>9999 )
                   continue;
               if( !iscow(ans) )
                   continue;
 
               count++;
          }
     }
     fo<<count<<endl;
}
 
int main()
{
    input();
    solve();
 
    return 0;
}
