#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int v,dis,cost;//该边末端结点编号、该边距离、该边权重
    Edge(int vv,int d,int c):v(vv),dis(d),cost(c){}//构造函数
};
vector<vector<Edge>>graph(505);//图
int dis[505],cost[505],pathLast[505];//存储起点到该点的最短距离、起点到该点的最小权重、起点到该点的父节点
bool visit[505];//存储起点到该点是否已被访问
int N,M,S,D;
void Dijkstra(){
    while(!visit[D]){//如果终点还没有被访问到
        int v=-1,MIN=INT_MAX;//在当前未访问的结点中找到距离最小的结点
        for(int i=0;i<N;++i)
            if(!visit[i]&&dis[i]<MIN){
                MIN=dis[i];
                v=i;
            }
        if(v==-1) return;//该图不是连通图，直接返回
        visit[v]=true;//置该点已被访问
        for(Edge&e:graph[v])//遍历该点能够到达的结点并更新相关信息
            if(!visit[e.v]&&dis[e.v]>dis[v]+e.dis){
                dis[e.v]=dis[v]+e.dis;
                cost[e.v]=cost[v]+e.cost;
                pathLast[e.v]=v;
            }else if(dis[e.v]==dis[v]+e.dis&&cost[e.v]>cost[v]+e.cost){
                cost[e.v]=cost[v]+e.cost;
                pathLast[e.v]=v;
            }
    }
}
void DFS(int v){//深度优先遍历输出最短路径
    if(v==S)
        printf("%d",v);
    else{
        DFS(pathLast[v]);
        printf(" %d",v);
    }
}
int main(){
    scanf("%d%d%d%d",&N,&M,&S,&D);
    for(int i=0;i<M;++i){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        graph[a].push_back(Edge(b,c,d));
        graph[b].push_back(Edge(a,c,d));
    }
    fill(dis,dis+N,INT_MAX);
    fill(cost,cost+N,INT_MAX);
    dis[S]=cost[S]=0;
    Dijkstra();
    DFS(D);
    printf(" %d %d",dis[D],cost[D]);
    return 0;
}
