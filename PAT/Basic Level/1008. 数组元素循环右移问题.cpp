#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    int a[N];
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    if(M>=N)//如果M>=N,需要取余
        M%=N;
    for(int i=0;i<M;++i){//需要移动M次
        int temp=a[N-M+i];//保存到临时变量
        for(int j=N-M+i;j>i;--j)//将需要移动的数后移一位
            a[j]=a[j-1];
        a[i]=temp;//将保存的临时变量赋值到数组中
    }
    for(int i=0;i<N;++i){
        printf("%s%d",i>0?" ":"",a[i]);
    }
    return 0;
}
