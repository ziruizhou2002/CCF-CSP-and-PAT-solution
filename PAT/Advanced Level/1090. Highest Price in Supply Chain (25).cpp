#include<bits/stdc++.h>
using namespace std;
int N,root,maxNum=0;
double P,R,S[100005],maxPrice=0.0;
vector<int>graph[100005];
void DFS(int v){//深度优先遍历
    if(S[v]>maxPrice){//当前单价比最高单价高
        maxPrice=S[v];//更新最高单价
        maxNum=1;//更新最高单价的数量为1
    }else if(S[v]==maxPrice)//当前单价与最高单价相等
        ++maxNum;//最高单价数量递增1
    for(int i:graph[v]){//遍历当前结点能到达的结点
        S[i]=S[v]*(1+R/100);//更新单价
        DFS(i);//递归遍历
    }
}
int main(){
    scanf("%d%lf%lf",&N,&P,&R);
    for(int i=0;i<N;++i){
        int a;
        scanf("%d",&a);
        if(a==-1)//输入的数为-1，即为当前结点root结点
            root=i;
        else
            graph[a].push_back(i);
    }
    S[root]=P;
    DFS(root);
    printf("%.2f %d",maxPrice,maxNum);
    return 0;
}
