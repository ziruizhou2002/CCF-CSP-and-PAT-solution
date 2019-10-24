#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    double A[N];
    for(int i=0;i<N;++i)
        scanf("%lf",&A[i]);
    sort(A,A+N);//排序
    double sum=A[0];
    for(int i=1;i<N;++i)
        sum=sum/2+A[i]/2;//对折两根绳子
    printf("%d",(int)floor(sum));//向下取整
    return 0;
}
