#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;++i)
        scanf("%d",&A[i]);
    sort(A,A+N);//排序
    int k=N-1;//记录当前最大的<=尝试的数在数组中的位置
    for(int i=N;i>=0;--i){//对N到0的数进行逐一尝试
        while(k>=0&&A[k]>i)//如果当前数，大于尝试的数，递减k，直至遇到最大的<=尝试的数
            --k;
        if(N-1-k>=i){//如果大于i的数>=i（即超过E英里的天数>=E）
            printf("%d",i);//这个数就是爱丁顿数，输出
            break;
        }
    }
    return 0;
}
