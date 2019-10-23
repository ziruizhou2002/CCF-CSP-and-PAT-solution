#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int v,cost[2];
};
int N,M,source,des,shortest[2];//source表示起点，des表示终点，shortest存储最短路径的长度(下标为0)和最快路径的时间(下标为1)
vector<Edge>graph[505];//图的邻接表
int dis[505],past[505],num[505];//存储到各点的最短距离、各点的父节点、还有一个辅助数组num，求最短路径时存储时间，求最快路径时存储当前路径上结点个数
bool visit[505];//是否已访问
vector<int>path[2];//下标为0存储最短路径，下标为1存储最快路径
void Dijkstra(int index){//Dijkstra算法，index==0时表示求的是最短路径；index==1时表示求的是最快路径
    while(!visit[des]){//还没有访问到终点
        int v=-1,MIN=INT_MAX;
        for(int i=0;i<N;++i)//求出目前距离最短的未访问结点
            if(!visit[i]&&MIN>dis[i]){
                MIN=dis[i];
                v=i;
            }
        if(v==-1)//不是连通图，直接返回
            return;
        visit[v]=true;//结点v已访问
        for(Edge&e:graph[v])//遍历v能到达的结点
            if(!visit[e.v]&&dis[e.v]>dis[v]+e.cost[index]){//距离更短
                dis[e.v]=dis[v]+e.cost[index];//更新距离
                past[e.v]=v;//更新父节点
                if(index==0)//求最短路径
                    num[e.v]=num[v]+e.cost[1];//更新到达当前结点时间
                else if(index==1)//求最快路径
                    num[e.v]=num[v]+1;//更新路径上结点个数
            }else if(dis[e.v]==dis[v]+e.cost[index])//距离相等
                if(index==0&&num[e.v]>num[v]+e.cost[1]){//求最短路径且时间更短
                    past[e.v]=v;//更新父节点
                    num[e.v]=num[v]+e.cost[1];//更新到达当前结点时间
                }else if(index==1&&num[e.v]>num[v]+1){//求最快路径且路径上结点数更少
                    past[e.v]=v;//更新父节点
                    num[e.v]=num[v]+1;//更新路径上结点个数
                }
    }
    shortest[index]=dis[des];//得出最短路径或最快路径的到达终点时的值
}
void DFS(int v,int index){//DFS算法求出路径，index==0时表示求的是最短路径；index==1时表示求的是最快路径
    if(v==source){//到达起点
        path[index].push_back(v);//将起点压入路径中
        return;//返回
    }
    DFS(past[v],index);//递归遍历
    path[index].push_back(v);//将当前点压入路径中
}
bool cmp(){//比较两个路径是否完全一致
    if(path[0].size()!=path[1].size())
        return false;
    for(int i=0;i<path[0].size();++i)
        if(path[0][i]!=path[1][i])
            return false;
    return true;
}
void output(int index){//输出路径
    for(int i=0;i<path[index].size();++i)
        printf("%s%d",i>0?" -> ":"",path[index][i]);
    printf("\n");
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int a,b,c,d,e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        graph[a].push_back({b,{d,e}});
        if(c==0)
            graph[b].push_back({a,{d,e}});
    }
    scanf("%d%d",&source,&des);
    for(int i=0;i<2;++i){//用两次Dijkstra+DFS算法
        fill(visit,visit+N,false);
        fill(dis,dis+N,INT_MAX);
        fill(num,num+N,INT_MAX);
        dis[source]=0;
        num[source]=0;
        Dijkstra(i);
        DFS(des,i);
    }
    if(cmp()){
        printf("Distance = %d; Time = %d: ",shortest[0],shortest[1]);
        output(0);
    }else{
        printf("Distance = %d: ",shortest[0]);
        output(0);
        printf("Time = %d: ",shortest[1]);
        output(1);
    }
    return 0;
}
