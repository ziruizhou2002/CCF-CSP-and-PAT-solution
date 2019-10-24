#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,maxIndex=0;//maxIndex存储最大子序列末尾数字所在索引
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;++i)
        scanf("%d",&A[i]);
    pair<int,int>dp[N]={{A[0],0}};//first元素存储子序列和，second元素存储子序列起始位置
    for(int i=1;i<N;++i){
        if(A[i]<=dp[i-1].first+A[i])
            dp[i]={dp[i-1].first+A[i],dp[i-1].second};
        else
            dp[i]={A[i],i};
        if(dp[i].first>dp[maxIndex].first)//更新最大子序列末尾数字所在索引
            maxIndex=i;
    }
    if(dp[maxIndex].first<0)//如果最大子序列和<0，说明都是负数
        printf("0 %d %d",A[0],A[N-1]);
    else
        printf("%d %d %d",dp[maxIndex].first,A[dp[maxIndex].second],A[maxIndex]);
    return 0;
}
