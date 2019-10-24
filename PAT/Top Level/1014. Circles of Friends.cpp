#include<bits/stdc++.h>
using namespace std;
int n,k,a,num=0,diameter=0;//num表示连通块个数，diameter存储相聚最远的结点所隔的最大结点个数
vector<int>graph[1005];//邻接表存储图
bool visit[1005];//标志一个结点是否已访问过
void BFS(int v){
    queue<int>q;
    q.push(v);
    int depth[n+1]={0};//每个点与起始点v的距离
    bool inQueue[n+1]={false};//标志一个结点是否已入队
    inQueue[v]=true;
    visit[v]=true;
    while(!q.empty()){
        v=q.front();
        q.pop();
        visit[v]=true;
        diameter=max(diameter,depth[v]-1);//更新diameter
        for(int i:graph[v]){
            if(!inQueue[i]){
                q.push(i);
                inQueue[i]=true;
                depth[i]=depth[v]+1;
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&k);
        while(k--){
            scanf("%d",&a);
            graph[a].push_back(i);
            graph[i].push_back(a);
        }
    }
    for(int i=1;i<=n;++i){
        if(!visit[i])//该点还没访问过
            ++num;//连通块个数+1
        BFS(i);//每个结点都进行一次BFS
    }
    printf("%d %d",num,diameter);
    return 0;
}
