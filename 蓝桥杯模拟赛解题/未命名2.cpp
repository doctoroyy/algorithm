#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
const int N = 29;
double num[N+2][N+2]={0};
double s(double a){
    //if(a%2 == 1)printf("error\n");
    return a/2;
}
int main()
{
    freopen("data2.txt","r",stdin);
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j <= i ; j ++)
        {
            scanf("%lf",&num[i][j]);
        //  num[i][j] *= kkk;
        }
    }
    for(int i = 1 ; i <= N; i ++){

        num[i][0] += s(num[i-1][0]);
        for(int j = 1 ; j < i ; j ++)
            num[i][j] += s(num[i-1][j-1]+num[i-1][j]);
        num[i][i] += s(num[i-1][i-1]);
    }
    int mi = 0,mx = 0;
    for(int i = 1 ; i <= N ; i ++)
    {
        if(num[N][i] > num[N][mx])mx = i;
        if(num[N][i] < num[N][mi])mi = i;
    }
    printf("%lf\n",num[N][mi]);
    printf("%lf\n",num[N][mx]*((long long)2086458231)/num[N][mi]);
    return 0;
}
