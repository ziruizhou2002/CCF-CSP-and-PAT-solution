#include<bits/stdc++.h>
using namespace std;
int N,minNum=0;
double P,R,S[100005],minPrice=INT_MAX*1.0;
vector<int>graph[100005];
void DFS(int v){//深度优先遍历
    if(graph[v].empty())//是零售商
        if(S[v]<minPrice){//当前单价比最高单价低
            minPrice=S[v];//更新最低单价
            minNum=1;//更新最低单价的数量为1
        }else if(S[v]==minPrice)//当前单价与最低单价相等
            ++minNum;//最低单价数量递增1
    for(int i:graph[v]){//遍历当前结点能到达的结点
        S[i]=S[v]*(1+R/100);//更新单价
        DFS(i);//递归遍历
    }
}
int main(){
    scanf("%d%lf%lf",&N,&P,&R);
    for(int i=0;i<N;++i){
        int m,a;
        scanf("%d",&m);
        while(m--){
            scanf("%d",&a);
            graph[i].push_back(a);
        }
    }
    S[0]=P;
    DFS(0);
    printf("%.4f %d",minPrice,minNum);
    return 0;
}
