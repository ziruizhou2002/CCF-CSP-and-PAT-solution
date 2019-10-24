#include<bits/stdc++.h>
using namespace std;
int N,M,K,T;
int graph[205][205];//用邻接矩阵存储图
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a][b]=graph[b][a]=c;
    }
    scanf("%d",&K);
    int shortindex=-1,shortdis=INT_MAX;//存储所有序列中路径长最短的序列编号以及最短路径长
    for(int i=1;i<=K;++i){
        scanf("%d",&T);
        int A[T],dis=0;//数组A存储给定序列，dis存储该序列的路径长
        bool cycle=true,simple=true,NA=false;
        unordered_map<int,int>mp;
        for(int j=0;j<T;++j){
            scanf("%d",&A[j]);
            if(j>0){//不是首节点时，开始进行相关计算
                ++mp[A[j]];//对结点出现次数进行累加
                NA=graph[A[j-1]][A[j]]==0?true:NA;//两点间无边置NA为true
                dis+=graph[A[j-1]][A[j]];//累计路径长
            }
        }
        cycle=!NA&&A[T-1]==A[0]&&mp.size()==N;//判断是否是一个环
        for(auto&ii:mp)//通过结点出现次数判断是否是简单环
            simple=ii.second>1?false:simple;
        printf("Path %d: ",i);
        if(NA)
            printf("NA");
        else
            printf("%d",dis);
        printf(" (%s)\n",cycle?(simple?"TS simple cycle":"TS cycle"):"Not a TS cycle");
        if(cycle&&dis<shortdis){//更新最短路径长
            shortdis=dis;
            shortindex=i;
        }
    }
    printf("Shortest Dist(%d) = %d",shortindex,shortdis);
    return 0;
}
