#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<int>graph[505];//图
bool visit[505];//是否已访问
void DFS(int v){//深度优先搜索
    visit[v]=true;
    for(int i:graph[v])
        if(!visit[i])
            DFS(i);
}
int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<N+1;++i)//输出点的度数
        printf("%s%d",i>1?" ":"",graph[i].size());
    DFS(1);//深度优先遍历
    if(find(visit+1,visit+N+1,false)-visit==N+1){//如果所有点都访问到，证明是连通图
        int k=count_if(graph+1,graph+N+1,[](vector<int>&a){//c++标准库自带函数，查找图中度数是奇数的顶点个数
                return a.size()%2==1;
    });
        if(k==0)
            printf("\nEulerian");
        else if(k==2)
            printf("\nSemi-Eulerian");
        else
            printf("\nNon-Eulerian");
    }else//不是连通图，直接输出Non-Eulerian
        printf("\nNon-Eulerian");
    return 0;
}
