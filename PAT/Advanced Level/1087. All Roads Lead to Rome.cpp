#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int v,cost;
};
vector<Edge>graph[205];
int city[205],dis[205],happiness[205];//每个城市的幸福值、到达每个城市时的距离和幸福值
int pathnum[205],past[205],pastnum[205];//到达每个城市时的最短路径条数、每个城市的前驱城市、到达每个城市前经过的城市
bool visit[205];//每个城市是否被访问过
unordered_map<string,int>STOI;//将城市字符串映射到整数
string ITOS[205];//将整数映射到字符串
int N,K;
void Dijkstra(int vend){
    while(!visit[vend]){//当未遍历到终点城市时
        int v=-1,MIN=INT_MAX;
        for(int i=0;i<N;++i)//找出当前未被访问的距离最小的城市
            if(!visit[i]&&MIN>dis[i]){
                v=i;
                MIN=dis[i];
            }
        if(v==-1)//图不连通直接返回
            return;
        visit[v]=true;//当前城市已访问
        for(Edge&e:graph[v])//遍历当前城市能到达的城市
            if(!visit[e.v]&&dis[e.v]>dis[v]+e.cost){//能到达的当前城市未被访问过且距离可更新
                dis[e.v]=dis[v]+e.cost;//更新到达该城市的距离
                happiness[e.v]=happiness[v]+city[e.v];//更新到达该城市的幸福值
                pastnum[e.v]=pastnum[v]+1;//更新到达该城市前遍历过的城市数
                past[e.v]=v;//更新到达该城市的前驱城市
                pathnum[e.v]=pathnum[v];//更新到达该城市的最短路径条数
            }else if(dis[e.v]==dis[v]+e.cost){//到达该城市时的距离与该城市储存的距离相等
                pathnum[e.v]+=pathnum[v];//更新到达该城市的最短路径条数
                if(happiness[e.v]<happiness[v]+city[e.v]||(happiness[e.v]==happiness[v]+city[e.v]&&pastnum[e.v]>pastnum[v]+1)){
                    past[e.v]=v;//更新到达该城市的前驱城市
                    happiness[e.v]=happiness[v]+city[e.v];//更新到达该城市的幸福值
                    pastnum[e.v]=pastnum[v]+1;//更新到达该城市的最短路径条数
                }
            }
    }
}
void DFS(int v){
    if(v==0){
        cout<<ITOS[v];
        return;
    }
    DFS(past[v]);
    cout<<"->"<<ITOS[v];
}
int main(){
    scanf("%d%d",&N,&K);
    cin>>ITOS[0];
    STOI.insert({ITOS[0],0});
    for(int i=1;i<N;++i){
        cin>>ITOS[i];
        STOI.insert({ITOS[i],i});
        cin>>city[i];
    }
    while(K--){
        int a;
        string s1,s2;
        cin>>s1>>s2>>a;
        graph[STOI[s1]].push_back(Edge({STOI[s2],a}));
        graph[STOI[s2]].push_back(Edge({STOI[s1],a}));
    }
    int vend=STOI["ROM"];//将ROM设置为终点城市
    fill(dis+1,dis+N,INT_MAX);//距离初始化为INT_MAX
    pathnum[0]=1;//起点城市最短路径条数设置为1
    Dijkstra(vend);
    printf("%d %d %d %d\n",pathnum[vend],dis[vend],happiness[vend],happiness[vend]/pastnum[vend]);
    DFS(vend);
    return 0;
}
