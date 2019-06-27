#include <algorithm>
#include <iostream>
#include <cstdio>
#include <bitset>
#include <queue>

using namespace std;

const int dx[]= {0,1,0,-1};
const int dy[]= {1,0,-1,0};
const int N=2e3+10 ;

struct Point {
  int x , y , turn ;
  Point():x(0),y(0),turn(0) {}
};
char a[N][N] ;
bitset<N>v[N];
int n , m ;

queue<Point>Q;

int main() {
  // freopen("testdata.in","r",stdin);
  Point s , t ;
  int i , j ;
  scanf("%d%d ",&n,&m);
//  for ( i=0 ; i<=n+1 ; i++ )
//    for ( j=0 ; j<=m+1 ; j++ ) a[i][j]='*';
  for ( i=1 ; i<=n ; i++ ) gets(a[i]+1);
  for ( i=1 ; i<=n ; i++ )
    for ( j=1 ; j<=m ; j++ )
      if ( a[i][j]=='S' ) s.x=i,s.y=j;
      else if ( a[i][j]=='T' ) t.x=i,t.y=j;
  Q.push(s);
  while ( !Q.empty() ) {
    Point now=Q.front();
    Q.pop();
    for ( i=0 ; i<4 ; i++ ) {
      Point son ;
      son.x=now.x+dx[i],son.y=now.y+dy[i];
      while ( a[son.x][son.y]!='*' && son.x<=n && son.x>=1 && son.y<=m && son.y>=1 ) {
        if ( !v[son.x][son.y] ) {
          if( son.x==t.x && son.y==t.y ) {
            printf("%d\n",now.turn);
            return 0 ;
          }
          v[son.x][son.y]=1,son.turn=now.turn+1,Q.push(son);
          cout << "mark£º(" << son.x << " " << son.y << ") "<< son.turn << endl;
        }
        son.x+=dx[i],son.y+=dy[i];
      }
    }
  }
  puts("troil");
  return 0 ;
}
