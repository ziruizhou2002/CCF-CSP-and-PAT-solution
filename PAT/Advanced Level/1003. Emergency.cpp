#include<bits/stdc++.h>
using namespace std;
struct Road{
    int v;//道路尽头的城市编号
    int length;//道路长度
    Road(int vv=0,int l=0):v(vv),length(l){}
};
vector<vector<Road>>graph(505);//图
int city[505],dis[505],pathNum[505],teamNum[505];//每个城市救护队的数量、到达每个城市的最短距离、到达每个城市的最短路径的数量、到达每个城市的救护队数量
bool visit[505];//每个城市是否被访问过
int N,M,C1,C2;
void Dijkstra(){
    while(!visit[C2]){//如果终点城市还没有被访问，继续循环
        int MIN=INT_MAX,v=-1;//找出目前距离最短的还没有被访问的城市
        for(int i=0;i<N;++i)
            if(!visit[i]&&dis[i]<MIN){
                MIN=dis[i];
                v=i;
            }
        visit[v]=true;//标记为已访问
        for(Road r:graph[v]){
            if(!visit[r.v]&&dis[r.v]>dis[v]+r.length){
                dis[r.v]=dis[v]+r.length;//更新最短路径长度
                pathNum[r.v]=pathNum[v];//更新最短路径数量
                teamNum[r.v]=teamNum[v]+city[r.v];//更新城市的救护队数量
            }else if(dis[r.v]==dis[v]+r.length){
                pathNum[r.v]+=pathNum[v];//增加最短路径数量
                teamNum[r.v]=max(teamNum[r.v],teamNum[v]+city[r.v]);//找出能够召集最多的城市救护队数量
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i=0;i<N;++i)
        scanf("%d",&city[i]);
    while(M--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back(Road(b,c));
        graph[b].push_back(Road(a,c));
    }
    fill(dis,dis+N,INT_MAX);//将最短路径均设置为最大值
    dis[C1]=0;//C1城市是起点，最短路径为0
    pathNum[C1]=1;//C1城市是起点，最短路径数量为1
    teamNum[C1]=city[C1];//C1城市是起点，能够召集的救护队数量为本城市的数量
    Dijkstra();
    printf("%d %d",pathNum[C2],teamNum[C2]);//输出
    return 0;
}
