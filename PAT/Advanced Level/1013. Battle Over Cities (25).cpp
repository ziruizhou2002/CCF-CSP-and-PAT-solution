#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph(1005);//存储图
bool visit[1005]={false};//标记相应编号的结点是否已被访问
void DFS(int v,int deleteV){//深度优先遍历，v表示当前正在访问的结点，deleteV表示删除的结点
    visit[v]=true;
    for(int i=0;i<graph[v].size();++i){
        int temp=graph[v][i];
        if(!visit[temp]&&temp!=deleteV)
            DFS(temp,deleteV);
    }
}
int N,M,K;
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    while(K--){
        int v;//删除的结点
        scanf("%d",&v);
        fill(visit+1,visit+N+1,false);//初始化visit为false
        int k=0;//连通分量的数量
        for(int i=1;i<N+1;++i)
            if(!visit[i]&&i!=v){
                DFS(i,v);
                ++k;
            }
        printf("%d\n",k-1);
    }
    return 0;
}
