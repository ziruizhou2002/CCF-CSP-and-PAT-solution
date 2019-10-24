#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int v,cost;
    Edge(int vv,int c):v(vv),cost(c){}
};
int Cmax,N,Sp,M;//四个参数
int weight[505],dis[505];//每个城市现有自行车数量、存储最短距离
bool visit[505];//是否已被访问
vector<vector<int>>pathLast(505);//存储最短路径中每个节点的父节点
vector<vector<Edge>>graph(505);//存储图
vector<int>path,currentPath;//path存储最短路径，currentPath存储当前最短路径
int Sent=INT_MAX,Collect=INT_MAX;//Sent表示从PBMC携带自行车数量，Collect表示从问题车站带回自行车数量
void Dijkstra(){//迪杰斯特拉算法
    while(!visit[Sp]){//如果访问到了问题车站，跳出循环
        int v=-1,MIN=INT_MAX;//找出未访问的节点中距离最小的
        for(int i=0;i<N+1;++i)
            if(!visit[i]&&MIN>dis[i]){
                MIN=dis[i];
                v=i;
            }
        visit[v]=true;//置该结点已访问
        for(Edge&e:graph[v])
            if(!visit[e.v]&&dis[e.v]>dis[v]+e.cost){//如果到达该结点的最短距离可更新成更短
                dis[e.v]=dis[v]+e.cost;//更新到达该结点的最短距离
                pathLast[e.v].clear();//更新目前最短路径中该结点的父节点
                pathLast[e.v].push_back(v);
            }else if(dis[e.v]==dis[v]+e.cost)//如果目前的路径与到达该结点的距离相等
                pathLast[e.v].push_back(v);//将当期路径中该结点的父节点压入
    }
}
void DFS(int v){//深度优先搜索
    if(v==0){//搜索到了PBMC结点
        int currentSent=0,currentCollect=0;//当前需要从PBMC携带自行车数量以及从问题车站带回自行车数量
        for(int i=currentPath.size()-1;i>=0;--i)//遍历当前的最短路径
            if(weight[currentPath[i]]>=0)//如果当前结点的自行车数量高于Cmax/2
                currentCollect+=weight[currentPath[i]];//将高于Cmax/2的自行车数量携带上
            else//如果当前结点的自行车数量低于Cmax/2
                if(currentCollect>=abs(weight[currentPath[i]])){//从路上携带的自行车多于当前结点需要补充的自行车数量
                    currentCollect+=weight[currentPath[i]];//将路上携带的自行车数量减去当前结点需要补充的自行车数量
                }else{//从路上携带的自行车少于当前结点需要补充的自行车数量
                    currentSent-=weight[currentPath[i]]+currentCollect;//需要在PBMC借出自行车
                    currentCollect=0;//路上携带的自行车数量置0
                }
        currentPath.push_back(v);//将PBMC结点压入当前最短路径
        if(currentSent<Sent){//当前路径从PBMC携带自行车数量更少
            Sent=currentSent;//更新各种参数
            Collect=currentCollect;
            path=currentPath;
        }else if(currentSent==Sent&&currentCollect<Collect){//当前路径从问题车站带回自行车数量更少
            Collect=currentCollect;//更新各种参数
            path=currentPath;
        }
        currentPath.pop_back();//弹出PBMC结点
        return ;
    }
    currentPath.push_back(v);//如果不是PBMC结点压入该结点
    for(int i=0;i<pathLast[v].size();++i)//遍历该结点的父节点，并递归调用深度优先遍历
        DFS(pathLast[v][i]);
    currentPath.pop_back();//弹出该结点
}
int main(){
    scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);//读入四个参数
    for(int i=1;i<=N;++i){//读入每个车站自行车数量并减去Cmax/2
        scanf("%d",&weight[i]);
        weight[i]-=Cmax/2;
    }
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back(Edge(b,c));
        graph[b].push_back(Edge(a,c));
    }
    fill(dis+1,dis+N+1,INT_MAX);//将最短距离置为最大值
    dis[0]=0;//PBMC结点最短距离为0
    Dijkstra();//调用Dijkstar算法
    DFS(Sp);//深度优先搜索
    printf("%d ",Sent);//进行输出
    for(int i=path.size()-1;i>=0;--i)
        printf("%s%d",i<path.size()-1?"->":"",path[i]);
    printf(" %d",Collect);
    return 0;
}
