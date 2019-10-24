#include<bits/stdc++.h>
using namespace std;
int N,L,K;
vector<int> graph[1005];//图
int BFS(int v){//广度优先遍历
    int num=0,level[N+1]={0};//num表示转发的人数，level表示用户转发时所处的转发层数
    bool visit[N+1]={false};//表示该用户是否已被访问过，即是否入过队
    queue<int>q;
    q.push(v);
    visit[v]=true;
    while(!q.empty()){
        v=q.front();
        q.pop();
        for(auto i:graph[v])//搜索关注该用户的人
            if(!visit[i]&&level[v]<L){//如果没有访问过且转发层数<L，更新相关信息
                ++num;
                visit[i]=true;
                level[i]=level[v]+1;
                q.push(i);
            }
    }
    return num;//返回转发人数
}
int main(){
    scanf("%d%d",&N,&L);
    for(int i=1;i<=N;++i){
        int num,a;
        scanf("%d",&num);
        while(num--){
            scanf("%d",&a);
            graph[a].push_back(i);
        }
    }
    scanf("%d",&K);
    while(K--){
        int a;
        scanf("%d",&a);
        printf("%d\n",BFS(a));
    }
    return 0;
}
